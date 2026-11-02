#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>  

// Для работы с цветом в консоли Windows
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

struct StringStats {
    int length;
    int word_count;
    int lower_count;
    int upper_count;
};

// Функция анализа строки
StringStats analyze_string(const char* str) {
    StringStats stats = { 0, 0, 0, 0 };
    stats.length = (int)strlen(str);

    bool in_word = false;
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];

        if (islower(c)) stats.lower_count++;
        if (isupper(c)) stats.upper_count++;

        // Подсчет слов
        if (!isspace(c)) {
            if (!in_word) {
                stats.word_count++;
                in_word = true;
            }
        }
        else {
            in_word = false;
        }
    }
    return stats;
}

// Вспомогательная функция для включения цвета в консоли
void set_color(bool highlight) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (highlight) {
        // Серый фон и черный текст для выделения области
        SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    }
    else {
        // Стандартный белый текст на черном фоне
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
#else
    if (highlight) {
        printf("\033[47;30m"); // ANSI серый фон, черный текст
    }
    else {
        printf("\033[0m");    // Сброс цвета
    }
#endif
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));
    printf("--- ЗАДАНИЕ №1 ---\n");

    int max_lines = 100;
    char** text_lines = (char**)malloc(max_lines * sizeof(char*));
    StringStats* stats_array = (StringStats*)malloc(max_lines * sizeof(StringStats));
    int line_count = 0;

    printf("Введите строки текста (для окончания ввода введите слово \"and\"):\n");

    char buff[256];
    while (true) {
        if (!fgets(buff, sizeof(buff), stdin)) break;

        // Удаляем символ переноса строки \n
        buff[strcspn(buff, "\n")] = '\0';

        // Проверка на признак окончания ввода "and"
        if (strcmp(buff, "and") == 0) {
            break;
        }

        // Выделение памяти под новую строку
        size_t dynamic_size = strlen(buff) + 1;
        text_lines[line_count] = (char*)malloc(dynamic_size);
        strcpy_s(text_lines[line_count], dynamic_size, buff);

        // Анализ строки и сохранение структуры характеристик
        stats_array[line_count] = analyze_string(text_lines[line_count]);

        line_count++;
        if (line_count >= max_lines) {
            max_lines *= 2;
            text_lines = (char**)realloc(text_lines, max_lines * sizeof(char*));
            stats_array = (StringStats*)realloc(stats_array, max_lines * sizeof(StringStats));
        }
    }

    // Сортировка строк по алфавиту
    for (int i = 0; i < line_count - 1; i++) {
        for (int j = 0; j < line_count - i - 1; j++) {
            if (strcmp(text_lines[j], text_lines[j + 1]) > 0) {
                // Переставляем указатели на строки
                char* temp_str = text_lines[j];
                text_lines[j] = text_lines[j + 1];
                text_lines[j + 1] = temp_str;

                // Переставляем соответствующие им характеристики
                StringStats temp_stats = stats_array[j];
                stats_array[j] = stats_array[j + 1];
                stats_array[j + 1] = temp_stats;
            }
        }
    }

    // Вывод отсортированного текста с характеристиками
    printf("\nРезультат Задания 1 (Строки по алфавиту + характеристики):\n");
    for (int i = 0; i < line_count; i++) {
        printf("%s [Длина: %d, Слов: %d, Строчных: %d, Прописных: %d]\n",
            text_lines[i],
            stats_array[i].length,
            stats_array[i].word_count,
            stats_array[i].lower_count,
            stats_array[i].upper_count);
    }

    // Освобождение памяти
    for (int i = 0; i < line_count; i++) {
        free(text_lines[i]);
    }
    free(text_lines);
    free(stats_array);

    printf("\n--- ЗАДАНИЕ №2 ---\n");

    int N, M;
    printf("Введите размеры матрицы N (строки) и M (столбцы): ");
    if (scanf_s("%d %d", &N, &M) != 2) return 1;

    // Выделение динамической памяти для вещественной матрицы NxM
    double** matrix = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(M * sizeof(double));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            double random_val = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
            matrix[i][j] = random_val;
        }
    }

    double** positive_ptrs = (double**)malloc((size_t)N * (size_t)M * sizeof(double*));
    int ptr_count = 0;

    // Визуализация матрицы с подсветкой заштрихованной области
    printf("\nМатрица (заштрихованная область выделена цветом):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Определяем заштрихованную область квадрантов
            bool in_shaded_area = (i >= N / 2.0 && j < M / 2.0) || (i < N / 2.0 && j >= M / 2.0);

            // Если в области и элемент положительный — сохраняем его указатель
            if (in_shaded_area && matrix[i][j] > 0) {
                positive_ptrs[ptr_count] = &matrix[i][j];
                ptr_count++;
            }

            // Выводим элемент с цветом или без
            set_color(in_shaded_area);
            printf(" %7.2f ", matrix[i][j]);
            set_color(false); // Сброс цвета
        }
        printf("\n");
    }

    // Вывод собранного массива результатов (указателей)
    printf("\nПоложительные элементы в заштрихованной области (через сохраненные указатели):\n");
    if (ptr_count == 0) {
        printf("Положительные элементы не найдены.\n");
    }
    else {
        for (int i = 0; i < ptr_count; i++) {
            printf("Значение: %7.2f (Адрес в памяти: %p)\n", *positive_ptrs[i], (void*)positive_ptrs[i]);
        }
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(positive_ptrs);

    return 0;
}

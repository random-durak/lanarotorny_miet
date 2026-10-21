#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N1 5
#define N2 7

// функция возвращения указателя на мин элемент массива
double* findMinPointer(double* arr, int size) {
    if (size <= 0) return NULL;

    double* min_ptr = &arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min_ptr) {
            min_ptr = &arr[i]; // адрес нового минимума
        }
    }
    return min_ptr;
}

int main() {
    setlocale(LC_ALL, "Rus");

    double A[N1];
    double B[N2];

    printf("Массив A: ");
    for (int i = 0; i < N1; i++) {
        // Формула генерирует случайное дробное число
        A[i] = ((double)rand() / RAND_MAX) * 50.0;
        printf("%.2f ", A[i]);
    }
    printf("\n");

    printf("Массив B: ");
    for (int i = 0; i < N2; i++) {
        B[i] = ((double)rand() / RAND_MAX) * 50.0;
        printf("%.2f ", B[i]);
    }
    printf("\n\n");

    // находим указатели на минимумы
    double* minPtrA = findMinPointer(A, N1);
    double* minPtrB = findMinPointer(B, N2);

    // находим индексы
    int indexA = minPtrA - A;
    int indexB = minPtrB - B;

    printf("Минимум в A: %.2f (индекс %d)\n", *minPtrA, indexA);
    printf("Минимум в B: %.2f (индекс %d)\n\n", *minPtrB, indexB);

    // ищем какой минимум ближе к концу массива
    int distA = (N1 - 1) - indexA;
    int distB = (N2 - 1) - indexB;

    if (distA < distB) {
        printf("Минимум в массиве A находится ближе к концу (осталось %d эл. до конца)\n", distA);
    } else if (distB < distA) {
        printf("Минимум в массиве B находится ближе к концу (осталось %d эл. до конца)\n", distB);
    } else {
        printf("Минимумы в обоих массивах находятся на одинаковом расстоянии от конца (%d эл.)\n", distA);
    }

    return 0;
}

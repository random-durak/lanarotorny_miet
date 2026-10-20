#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 6
#define M 8

// Функция поиска максимума в верхней левой области и минимума в нижней правой области
void findValues(int a[N][M], int* max, int* min)
{
    *max = a[0][0]; // Инициализируем первым элементом области
    *min = a[N / 2][M / 2]; // Инициализируем первым элементом нижней области

    // Поиск максимума в верхней левой области
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < M / 2; j++)
        {
            if (a[i][j] > *max)
                *max = a[i][j];
        }
    }

    // Поиск минимума в нижней правой области
    for (int i = N / 2; i < N; i++)
    {
        for (int j = M / 2; j < M; j++)
        {
            if (a[i][j] < *min)
                *min = a[i][j];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int A[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = rand() % 90 + 10;
        }
    }

    printf("Сгенерированная матрица:\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((i < N / 2 && j < M / 2) || (i >= N / 2 && j >= M / 2))
            {
                printf("\033[1;32m%3d\033[0m", A[i][j]);
            }
            else
            {
                printf("%3d", A[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    int max, min;
    findValues(A, &max, &min);
    printf("Ответ:\n");
    printf("Максимум в верхней области: %d\n", max);
    printf("Минимум в нижней области: %d\n", min);

    return 0;
}

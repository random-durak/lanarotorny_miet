#include <stdio.h>

#define N 6
#define M 8
#include <locale.h>
// Функция поиска максимума в верхней левой области и минимума в нижней правой области
void findValues(int a[N][M], int* max, int* min)
{
    setlocale(LC_ALL, "Rus");
    *max = a[0][0];
    *min = a[N / 2][M / 2];
    // Верхняя левая область
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < M / 2; j++)
        {
            if (a[i][j] > *max)
                *max = a[i][j];
        }
    }
    // Нижняя правая область
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
    int A[N][M] = {
        {1,  5,  3,  7,  2,  4,  8,  6},
        {9,  2,  6,  4,  3,  1,  5,  7},
        {4,  8,  2,  9,  5,  6,  3,  1},
        {7,  3,  5,  2,  8,  4,  6,  9},
        {6,  1,  4,  3,  2,  5,  7,  8},
        {2,  9,  7,  1,  4,  6,  3,  5}
    };
    int max, min;
    // Находим максимум и минимум
    findValues(A, &max, &min);
    printf("Максимум в верхней области: %d\n", max);
    printf("Минимум в нижней области: %d\n", min);
    return 0;
}
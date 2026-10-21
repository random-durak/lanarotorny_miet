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
    A[i][j] = rand() % 50 + 1; 
    };
    int max, min;
    // Находим максимум и минимум
    findValues(A, &max, &min);
    printf("Максимум в верхней области: %d\n", max);
    printf("Минимум в нижней области: %d\n", min);
    return 0;
}
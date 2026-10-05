#include <stdio.h>
#include <locale.h>

// ‘ункци€ поиска индекса последнего положительного элемента
int lastPositive(int a[], int n)
{
    setlocale(LC_ALL, "Rus");
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            index = i;
    }
    return index;
}

int main()
{
    int A[8] = { -5, 3, -2, 7, -8, -4, 6, -1 };
    int B[7] = { 4, -3, 5, -7, -2, 8, -6 };
    int index, count;
    index = lastPositive(A, 8);
    count = 0;
    // ѕодсчЄт отрицательных элементов во второй части массива
    for (int i = index + 1; i < 8; i++)
    {
        if (A[i] < 0)
            count++;
    }
    printf("A: индекс последнего положительного %d, кол-во отрицательных во 2 части массива %d\n", index, count);
    index = lastPositive(B, 7);
    count = 0;
    for (int i = index + 1; i < 7; i++)
    {
        if (B[i] < 0)
            count++;
    }
    printf("B: индекс последнего положительного %d, кол-во отрицательных во 2 части массива %d\n", index, count);
    return 0;
}
// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    //#2
    int a[8][12];
    int b[4]; //одномерный массив из 4 элементов
    int i, j;
    int max, min;
    int k;
    //заполнение матрицы случайными числами
    for (i = 0; i < 8; i++)
        for (j = 0; j < 12; j++)
            a[i][j] = rand()%100;
    max = a[0][1];
    //перебор строк
    for (i = 0; i < 8; i++) {
        //перебор столбцов
        for (j = 0; j < 12; j++) {
            if (j > i && a[i][j] > max)
                max = a[i][j];
        }
    }
    min = a[1][0];
    //поиск макс элемента
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 12; j++) {
            if (i > j && a[i][j] < min)
                min = a[i][j];
        }
    }
    k = 0;
    //подсчет нулей в нечетных строках
    for (i = 0; i < 8; i += 2)
    {
        b[k] = 0;
        for (j = 0; j < 12; j++) {
            if (a[i][j] == 0)
                b[k]++;
        }
        k++;
    }
    printf("максимум в верхней области: %d\n", max);
    printf("минимум в нижней области: %d\n", min);
    printf("массив содержащий количество нулей в нечетных строках:\n");
    //вывод массива б
    for (i = 0; i < 4; i++)
        printf("%d ", b[i]);
    return 0;
}
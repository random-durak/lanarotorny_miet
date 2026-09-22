// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>

int main()
{
    //#1
    setlocale(LC_ALL, "Rus");
    int n; //колво элементов массива
    int x[100]; //массив
    int sum = 0;
    int k = 0; //колво элементов меньше ср.ариф.
    int min;
    int num = 0;
    float sr;
    int i;
    printf("введите количество элементов массива: ");
    scanf_s("%d", &n);
    printf("теперь вводите значения элементов через энтер: ");
    for (i = 0; i < n; i++) {
        scanf_s("%d", &x[i]);
        sum += x[i];
    }
    sr = sum / n;
    for (i = 0; i < n; i++) {
        if (x[i] < sr) {
            k++;
        }
    }
    //поиск минимального положительного массива
    for (i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            if (num==0 or x[i] < min)
            {
                min = x[i];
                num = i;
            }
        }
    }
    printf("количество элементов меньше ср.ариф: %d\n", k);
    printf("номер минимального положительного элемента: %d\n", num + 1);
    return 0;
}
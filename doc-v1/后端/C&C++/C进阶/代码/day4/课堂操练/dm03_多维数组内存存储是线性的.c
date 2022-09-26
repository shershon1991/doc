#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void printfArray31(int *array, int size)
{
          int i = 0;

          for (i = 0; i < size; i++)
          {
                    printf("%d ", array[i]);
          }
}

void main31()
{
          int a[3][5];
          int i, j = 0;
          int tmp = 1;

          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              a[i][j] = tmp++;
                    }
          }

          //把2维数组当成1维数组来打印，证明是线性存储的
          printfArray31((int *)a, 15);

          system("pause");
          return;
}

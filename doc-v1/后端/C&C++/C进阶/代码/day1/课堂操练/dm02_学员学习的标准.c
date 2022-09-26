#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//void printArray(int a[], int num)
void printArray(int *a, int num)
{
          int i;
          for (i = 0; i < 7; i++)
          {
                    printf("%d\n", a[i]);
          }
}

//void sortArray(int a[], int num)
void sortArray(int *a, int num)
{
          int num2;
          num2 = sizeof(a) / sizeof(a[0]);
          printf("num2=%d\n", num2);
          //实参的a和形参的a的数据类型本质不一样
          //形参中的数组，编译器会把它当成指针来处理 这是C语言的特色

          int i, j, temp;
          for (i = 0; i < 7 - 1; i++)
          {
                    for (j = 0; j < 7 - i - 1; j++)
                    {
                              if (a[j] > a[j + 1])
                              {
                                        temp = a[j];
                                        a[j] = a[j + 1];
                                        a[j + 1] = temp;
                              }
                    }
          }
}

//数组做函数参数的退回问题 退回为一个指针
//1.结论：把数组的内存首地址和数组的有效长度传递给被调用的函数
//2.实参的a和形参的a的数据类型本质不一样
//形参中的数组，编译器会把它当成指针来处理 这是C语言的特色
void main21()
{
          int num;
          int a[] = {12, 45, 76, 34, 78, 234, 65};
          num = sizeof(a) / sizeof(a[0]);
          printf("num=%d\n", num);

          printf("排序之前\n");
          printArray(a, num);

          //排序
          sortArray(a, num);

          printf("排序之后\n");
          printArray(a, num);

          printf("hello...\n");
          system("pause");
}
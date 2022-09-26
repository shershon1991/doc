#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void printArray21(int a[3][5])
{
          int i, j, tmp = 0;
          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              printf("%d ", a[i][j]);
                    }
          }
}

void printArray22(int a[][5])
{
          int i, j, tmp = 0;
          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              printf("%d ", a[i][j]);
                    }
          }
}

void printArray23(int (*b)[5])
{
          int i, j, tmp = 0;
          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              printf("%d ", b[i][j]);
                    }
          }
}

//多维数组做函数参数退化过程
//为什么存在退化？
void main21()
{
          int i, j = 0;
          int a[3][5] = {0};
          int tmp = 1;

          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              a[i][j] = tmp++;
                    }
          }

          printf("--------------\n");
          printArray23(a);

          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              printf("%d ", a[i][j]);
                    }
          }

          //多维数组名a代表什么
          printf("a:%d, a+1:%d \n", a, a + 1);
          printf("&a:%d, &a+1:%d \n", &a, &a + 1);

          //定义一个指向数组的指针变量
          int(*pArray)[5]; //告诉编译器分配4个字节的内存，32bit平台下
          pArray = a;

          for (i = 0; i < 3; i++)
          {
                    for (j = 0; j < 5; j++)
                    {
                              printf("%d ", pArray[i][j]);
                    }
          }

          //多维数组名的本质 就是数组指针（步长是一维的长度）

          //(a+i)	代表是整个第i行的地址 二级指针
          //*(a+i)	代表是第i行首元素的地址 一级指针
          //*(a+i)+j	代表第i行，第j列的地址==》&a[i][j]

          //a[i][j] <==> *(*(a+i)+j)

          //a[i] ===> a[0+i] ===> *(a+i)

          //a[i][j] ===> a[0+i][j] ===> *(a+i)[j] ===> *(a+i)[0+j] ===> *(*(a+i)+j)

          system("pause");
          return;
}

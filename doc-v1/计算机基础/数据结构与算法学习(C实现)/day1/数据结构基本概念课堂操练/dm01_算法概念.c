#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//算法的最终要编译成具体的计算机指令
//每一个指令 在具体的计算机CPU上运行的时间是固定的
//通过具体的n的步骤的多少就可以推导出算法的复杂度
long sum1(int n) //2n+4 ===> O(n)
{
          int i = 0;                                   //1
          long ret = 0;                                //1
          int *array = (int *)malloc(n * sizeof(int)); //1

          for (i = 0; i < n; i++) //n
          {
                    array[i] = i + 1;
          }

          for (i = 0; i < n; i++) //n
          {
                    ret += array[i];
          }

          free(array); //1
          return ret;
}

long sum2(int n) //n+2 ===> O(n)
{
          int i = 0;    //1
          long ret = 0; //1

          for (i = 1; i <= n; i++) //n
          {
                    ret += i;
          }

          return ret;
}

long sum3(int n) //2 ==> O(1)
{
          long ret = 0; //1

          if (n > 0)
          {
                    ret = (1 + n) * n / 2; //1
          }

          return ret;
}

void main101()
{
          printf("%d\n", sum1(100));
          printf("%d\n", sum2(100));
          printf("%d\n", sum3(100));

          system("pause");
          return;
}

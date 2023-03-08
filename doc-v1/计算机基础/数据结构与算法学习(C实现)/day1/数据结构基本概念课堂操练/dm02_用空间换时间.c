/*
	问题：
	在一个由1-1000中某些数字组成的数组中，每个数字可能出现零次或者多次
	设计一个算法，找出出现次数最多的数字
	int array[2000] = {1,2,3,56,33,44,3,5,2,6,21}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void search(int a[], int len)
{
          int i = 0, max = 0;
          int sp[1000] = {0};

          for (i = 0; i < len; i++) //遍历数组，求出每一个数字出现的次数，然后记录下来
          {
                    int index = a[i] - 1;
                    sp[index]++;
          }

          for (i = 0; i < 1000; i++) //扫描数组最大的数
          {
                    if (max < sp[i])
                    {
                              max = sp[i];
                    }
          }

          for (i = 0; i < 1000; i++) //打印数字出现次数最多的数
          {
                    if (max == sp[i])
                    {
                              printf("%d\n", i + 1);
                    }
          }
}

void main201()
{
          int array[] = {1, 1, 3, 4, 6, 4, 3, 2, 2, 6, 8, 9, 3, 3};
          search(array, sizeof(array) / sizeof(*array));

          system("pause");
          return;
}
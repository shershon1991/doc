#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main51()
{
          int i = 0;

          //指针数组
          char *p[] = {"123", "456", "789"};

          //二维数组
          char p2[3][4] = {"123", "456", "789"};

          //手工打造二维内存
          char **p3 = (char **)malloc(sizeof(char *) * 3); //int array[3]

          for (i = 0; i < 3; i++)
          {
                    p3[i] = (char *)malloc(sizeof(char *) * 10); //int array[3]
                    sprintf(p3[i], "%d%d%d", i, i, i);
          }

          system("pause");
          return;
}
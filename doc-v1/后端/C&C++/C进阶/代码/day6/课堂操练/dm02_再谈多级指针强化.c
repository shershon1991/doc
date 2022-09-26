#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void getMem21(char *p1)
{
          *p1 = 20;
}

void getMem22(char **p2 /*out*/)
{
          *p2 = 30; //间接赋值，p2是p的地址

          *p2 = (char **)malloc(1000);
}

void main22()
{
          int a = 0;
          char *p1 = NULL;
          char **p2 = NULL;

          //p1 = 1;
          //p1 = 2;//直接修改p的值
          p1 = &a;
          getMem21(p1);
          printf("a:%d \n", a);

          system("pause");
          return;
}

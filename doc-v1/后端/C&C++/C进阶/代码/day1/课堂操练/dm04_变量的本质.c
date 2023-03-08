#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main41()
{
          int a;
          int b[10];
          char *p = &a;

          a = 10; //直接赋值
          printf("&a:%d\n", &a);

          *p = 200; //间接赋值
          printf("a:%d\n", a);

          printf("hello ...\n");
          system("pause");
}

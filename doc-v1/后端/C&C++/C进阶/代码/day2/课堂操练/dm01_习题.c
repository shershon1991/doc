#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//野指针产生的原因：
//指针变量和它所指的内存空间变量是两个不同的概念
//释放了指针所指的内存空间 但是指针变量本身没有重置成NULL

//避免方法：1.定义指针的时候，初始化为NULL；2.释放指针所指向的内存空间后，把指针重置为NULL
void main11()
{
          char *p1 = NULL;
          p1 = (char *)malloc(100);
          if (p1 == NULL)
          {
                    return;
          }
          strcpy(p1, "123456");
          printf("p1:%s\n", p1);

          if (p1 != NULL)
          {
                    free(p1);
                    p1 = NULL;
          }
          printf("p1:%s\n", p1);

          printf("hello...\n");
          system("pause");
          return;
}
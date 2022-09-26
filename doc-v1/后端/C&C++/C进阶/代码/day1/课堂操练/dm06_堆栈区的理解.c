#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//堆
char *getMem(int num)
{
          char *p1 = NULL;
          p1 = (char *)malloc(sizeof(char) * num);
          if (p1 == NULL)
          {
                    return NULL;
          }
          return p1;
}

//栈
//注意：return 不是把64个字节的内存块返回了，而是把内存块的首地址（内存的标号）返回给tmp

//理解指针的关键是内存（没有内存就没有首地址编号，没有编号就没有指针）
char *getMem2()
{
          char buf[64]; //临时变量，栈区存放
          strcpy(buf, "1234567890");
          //printf("%s\n",buf);
          return buf;
}

void main61()
{
          char *tmp = NULL;
          tmp = getMem(10);
          if (tmp == NULL)
          {
                    return;
          }
          strcpy(tmp, "123456"); //往指针指向的空间中copy数据

          tmp = getMem2();

          printf("hello tmp:%s\n", tmp);

          printf("hello ...\n");
          system("pause");
}

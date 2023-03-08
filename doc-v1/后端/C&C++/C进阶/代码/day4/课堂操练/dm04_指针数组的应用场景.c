#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//求关键字在表中的位置
//#define DIM(a) (sizeof(a)/sizeof(*a))

void main41()
{
          int num = 0;
          int pos = 0;
          int a[10];
          int i = 0;
          //指针数组
          char *c_keyword[] = {
              "while",
              "case",
              "static",
              "do"};

          //searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
          printf("pos:%d\n", pos);
          //searchKeyTable(c_keyword, DIM(c_keyword), "static", &pos);

          system("pause");
          return;
}

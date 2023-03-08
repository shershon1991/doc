#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main81()
{
          int a = 10;
          int *p1 = 100; //分配4个字节的内存
          int ****p2 = 100;
          int *p3 = NULL;

          p3 = &a;
          *p3 = 20; //间接地修改a的值
          //*就像一把钥匙，通过指针去间接修改a变量标识的内存空间

          {
                    int c;
                    c = *p3; //c=20
                    //*p放在=左边，写内存
                    //*p放在=右边，读内存
                    printf("c:%d\n", c);
          }

          {
                    char *p4 = NULL;
                    p4 = (char *)malloc(100);
                    printf("p4:%d\n", p4);
                    p4 = (char *)malloc(100);
                    printf("p4:%d\n", p4);
          }

          printf("a:%d, p1:%d, p2:%d\n", sizeof(a), sizeof(p1), sizeof(p2));
          printf("hello...");
          system("pause");
          return;
}

char *getStr81()
{
          char *tmp = NULL;
          tmp = "abcdefg";
          return tmp;
}

int getABC1(char *p1);
int getABC2(char **p2);
int getABC3(char ***p3);
int getABC4(char (*p4)[30]);
int getABC5(char p5[10][30]);

void main82()
{
          char *p = getStr81();
          printf("p:%s\n", p);
          //*(p + 2) = 'r';//经常出现的错误，保证指针所指向的内存空间可以被修改

          system("pause");
          return;
}
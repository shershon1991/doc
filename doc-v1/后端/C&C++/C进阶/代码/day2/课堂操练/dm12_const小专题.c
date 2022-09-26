#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void getmem121(char *p)
{
          p = 2;
          p = 3;
          //p[1] = 'a';
          return;
}

void getmem122(char *p)
{
          p[1] = 'a';
          p = 1;
          return;
}

void getmem123(const char *p)
{
          //p[1] = 'a';
          printf("%c", p[1]);
          return;
}

void main121()
{
          /*char* p1 = NULL;
	const char* p2 = "abcd";
	p2 = 1;
	getmem121(p2);
	printf("p2:%d \n", p2);*/

          /*char* const p2 = "abcd";
	getmem122(p2);
	printf("p2:%s \n", p2);*/

          char *const p2 = "abcd";
          getmem123(p2);

          system("pause");
          return;
}

void main122()
{
          const int a = 10; //结论：C语言中的const修饰的变量是假的，C语言中的const是一个冒牌货
          //a = 11;

          {
                    int *p = &a;
                    *p = 100;
                    printf("%d\n", a);
          }

          system("pause");
          return;
}
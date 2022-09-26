#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char g_buf[1000];

/*int inverse(char* str1, char* str2)
{
}*/

void main101()
{
          char buf[] = "abcdefg";
          int len = strlen(buf);

          char *p1 = buf;
          char *p2 = buf + len - 1;

          while (p1 < p2)
          {
                    char c = *p1;
                    *p1 = *p2;
                    *p2 = c;
                    ++p1;
                    --p2;
          }
          printf("buf:%s \n", buf);

          system("pause");
          return;
}

//1.通过递归的方式，逆向打印
//2.递归和全局变量（把逆序的结果存入全局变量）
//3.递归和非全局变量（递归指针做函数参数）
void inverse02(char *p)
{
          if (p == NULL)
          {
                    return;
          }
          if (*p == '\0')
          {
                    return;
          }
          inverse02(p + 1); //注意 此时没有执行打印，而是执行了函数调用，字符串的每一个地址入栈
          printf("%c", *p);
}

void inverse03(char *p)
{
          if (p == NULL)
          {
                    return;
          }
          if (*p == '\0')
          {
                    return;
          }
          inverse03(p + 1); //注意 此时没有执行打印，而是执行了函数调用，字符串的每一个地址入栈
          //printf("%c", *p);
          //strncpy(g_buf, p, 1);
          strncat(g_buf, p, 1);
}

void inverse04(char *p, char *bufresult)
{
          if (p == NULL || bufresult == NULL)
          {
                    return;
          }
          if (*p == '\0')
          {
                    return;
          }
          inverse04(p + 1, bufresult); //注意 此时没有执行打印，而是执行了函数调用，字符串的每一个地址入栈
          strncat(bufresult, p, 1);
}

void main102()
{
          char buf[] = "abcdefg";
          //inverse02(buf);

          /*memset(g_buf, 0, sizeof(g_buf));
	inverse03(buf);		
	printf("g_buf:%s \n", g_buf);*/

          {
                    char mybuf[1024] = {0};
                    inverse04(buf, mybuf);
                    printf("递归和局部变量在一起mybuf:%s \n", mybuf);
          }

          system("pause");
          return;
}
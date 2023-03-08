#include <stdio.h>
#include <string.h>

int mystrlen(char str[]);
int max(int a, int b);

int test(int n)
{
          n++;
          printf("n = %d\n", n);
}

void test_str(char s[])
{
          s[0] = 'a';
          s[1] = 'b';
}

//调用函数要求：1、在调用之前定义这个函数；2、在调用函数之前声明这个函数，在后面再定义这个函数
int main()
{
          /*char str1[100] = "hello";
	test_str(str1);
	printf("%s\n", str1);*/

          /*int value = 9;
	test(value);
	printf("value = %d\n", value);*/

          //int c = max(11, 12);
          //printf("c = %d\n", c);

          char s[100] = "hello";
          int len = mystrlen(s); //s-实参
          printf("%d\n", len);

          system("pause");
          return 0;
}

int mystrlen(char str[]) //str-形参
{
          int len = 0;
          while (str[len++])
                    ;
          len--;
          return len;
}

int max(int a, int b)
{
          int c = (a > b) ? a : b;
          return c;
}
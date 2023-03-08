#include <stdio.h>

void test(int n)
{
          if (n > 0)
          {
                    n--;
                    printf("n = %d\n", n); //先序递归，如果是先序递归，代码顺序执行
                    test(n);               //函数自己调用自己，就叫函数的递归
                    printf("n = %d\n", n); //后序递归，代码是逆序执行
          }
}

void test1(int n)
{
          int i = 0;
          for (i = 0; i < n; i++)
          {
                    printf("i = %d\n", i);
          }
}

void test2(int n)
{
          if (n > 0)
          {
                    n--;
                    test2(n);
                    printf("%d\n", n);
          }
}

int age(int n)
{
          if (n == 1)
                    return 10; //第一个人年龄是10岁
          else
          {
                    return age(n - 1) + 2; //前一个人比后一个人年龄大2岁
          }
}

int hex1(int n)
{
          switch (n)
          {
          case 1:
                    return '1';
          case 2:
                    return '2';
          case 3:
                    return '3';
          case 4:
                    return '4';
          case 5:
                    return '5';
          case 6:
                    return '6';
          case 7:
                    return '7';
          case 8:
                    return '8';
          case 9:
                    return '9';
          case 10:
                    return 'A';
          case 11:
                    return 'B';
          case 12:
                    return 'C';
          case 13:
                    return 'D';
          case 14:
                    return 'E';
          case 15:
                    return 'F';
          default:
                    return '0';
          }
}

void bin(int n)
{
          int i = n % 2;
          if (n > 0)
          {
                    bin(n / 2);
                    printf("%d", i);
          }
}

void hex(int n)
{
          int i = n % 16;
          if (n > 0)
          {
                    hex(n / 16);
                    printf("%c", hex1(i));
          }
}

//用递归实现求字符串的长度
int mystrlen(char s[], int n)
{
          if (s[n])
          {
                    return mystrlen(s, n + 1);
          }
          else
          {
                    return n;
          }
}

int main()
{
          printf("%d\n", mystrlen("hello", 0));
          int i = 12;
          //hex(i);
          //bin(i);
          //printf("age = %d\n", age(i));
          return 0;
}
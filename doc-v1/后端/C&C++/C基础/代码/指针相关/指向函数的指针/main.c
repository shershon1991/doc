#include <stdio.h>
#pragma warning(disable : 4996)

int add(int a, int b)
{
          return a + b;
}

int max(int a, int b)
{
          return a > b ? a : b;
}

void print_array(int *s, int n)
{
          int i;
          for (i = 0; i < n; i++)
          {
                    printf("%d\n", s[i]);
          }
}

int main1()
{
          //void *p(int, char *);//声明了一个函数，函数的名字为p,返回值为void *,函数的参数分别为int,char *
          //void (*p)(int, char *);//定义了一个指向参数为int和char *，返回值为void的函数指针
          //void(*p)(int *s, int n);void(*p)(int *, int);
          int (*p)(int, int); //定义一个指向函数的指针，可以指向两个函数，都是int，返回值也是int

          int status = 0;
          scanf("%d", &status);
          if (status == 1)
                    p = max;
          else
                    p = add;
          //p = add;//将add函数的地址赋值给指针变量p
          int i;
          i = p(5, 7); //通过指针变量间接地调用函数
          //在编译i = p(5,7)时，不知道调用什么代码
          printf("i = %d\n", i);

          p = print_array;
          int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          p(buf, 10);

          return 0;
}

int func1(int (*p)(int, int), int a, int b)
{
          return p(a, b);
}

int main()
{
          int i = func1(max, 6, 9); //add函数在这里叫做回调函数
          printf("i = %d\n", i);
          return 0;
}
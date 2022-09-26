#include <stdio.h>

int c = 0; //在静态区

void test(int *a, int *b)
{
          printf("%d, %d\n", a, b);
}

int main1()
{
          static int d = 0; //在静态区
          auto int a = 0;   //在栈区
          auto int b = 0;   //在栈区

          printf("%d, %d, %d, %d\n", &a, &b, &c, &d);
          test(&a, &b);

          system("pause");
          return 0;
}

int main2()
{
          //char array[1024 * 1024] = {0};//1M，定义一个超大的数组，就会栈溢出
          char array[1024] = {0}; //1M，定义一个超大的数组，就会栈溢出
          array[0] = 'a';
          printf("%s\n", array);

          system("pause");
          return 0;
}
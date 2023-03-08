#include <stdio.h>

void test(); //声明一个函数

int main()
{
          test();

          system("pause");
          return 0;
}

void test() //返回值是void，代表不返回任何值
{
          printf("test\n");
          return;
}
#include <iostream>
using namespace std;

//C语言中的变量都必须在作用域开始的位置定义
//C++中更强调语言的“实用性”，所有的变量都可以在需要使用时再去定义
void main401()
{
          int i;
          printf("hello ...\n");

          int k;
          i = 10;
          k = 11;
          printf("i:%d, k:%d \n", i, k);

          system("pause");
}

void main402()
{
          register int a = 0;

          printf("&a:%d \n", &a); //C不能在寄存器变量上取地址,C++可以

          system("pause");
          return;
}

//变量检测增强
int g_a = 100;
//int g_a;
void main403()
{
          printf("g_a:%d \n", g_a);
          system("pause");
}

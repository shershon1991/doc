#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main11()
{
          int i;
          printf("hello ...\n");

          int k;

          i = 10;
          k = 11;
          printf("i:%d, k:%d \n", i, k);

          system("pause");
          return;
}

void main12()
{
          register int a = 0;

          //printf("%a:%d \n", &a);//err:不能再寄存器变量上取地址

          system("pause");
          return;
}

int g_a = 100;
int g_a;
void main13()
{
          printf("g_a:%d \n", g_a);
          system("pause");
}

struct Teacher
{
          char name[32];
          int age;
};
void main14()
{
          struct Teacher t1;
          t1.age = 28;

          system("pause");
}

//C++中所有的变量和函数都必须有类型
//C语言中的默认类型在C++中是不合法的
//函数f的返回值是什么类型，参数又是什么类型？
//函数g可以接收多少个参数？
//更换成.cpp试试
f(i)
{
          printf("i:%d \n", i);
}
g()
{
          return 5;
}
int main15(int argc, char *argv[])
{
          f(10);
          printf("g() = %d\n", g(1, 2, 3, 4, 5));

          getchar();
          return 0;
}

//在C语言中，表达式的运算结果是放在寄存器里面的
//在C语言中，表达式的返回值 是变量的值
//在C++中，表达式返回的是变量的本身
int main16()
{
          int a = 10;
          int b = 20;

          //返回一个最小数，并且给最小数赋值成30
          //三目运算符是一个表达式，表达式不可能做左值
          //(a < b ? a : b) = 30;
          *(a < b ? &a : &b) = 30;

          printf("a = %d, b = %d \n", a, b);

          system("pause");
          return 0;
}

//C语言中的const是冒牌货
void main17()
{
          //好像a是一个常量
          const int a = 10;
          //a = 11;

          int *p = NULL;
          p = &a;
          *p = 20;

          printf("a:%d \n", a);
          system("pause");
}
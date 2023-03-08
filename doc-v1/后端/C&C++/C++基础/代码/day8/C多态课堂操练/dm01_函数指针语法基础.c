#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//数据类型基本语法
//1.定义一个数组类型
//2.定义一个指针数组类型
//3.定义一个指向数组类型的指针 数组指针
void main101()
{
          int a[10]; //a代表的是数组首元素的地址，&a代表整个数组的地址	a+1 &a+1步长不一样

          //定义一个数组类型
          {
                    typedef int(myTypeArray)[10];
                    myTypeArray myArray;
                    myArray[0] = 10;
                    printf("a[0]:%d \n", myArray[0]);
          }

          //定义一个指针数组类型
          {
                    typedef int(*PTypeArray)[10];
                    PTypeArray myPArray;
                    myPArray = &a;
                    (*myPArray)[0] = 20;
                    printf("a[0]:%d \n", a[0]);
          }

          //定义一个指向数组类型的指针 数组指针
          {
                    int(*myPointer)[10]; //变量 告诉编译器 给我分配内存
                    myPointer = &a;
                    (*myPointer)[0] = 30;
                    printf("a[0]:%d \n", a[0]);
          }

          system("pause");
          return;
}

//函数指针基本语法
//1.如何定义一个函数类型
//2.如何定义一个函数指针类型
//3.如何定义一个函数指针（指向一个函数的入口地址）
int add(int a, int b)
{
          printf("func add() ... \n");
          return a + b;
}
void main102()
{
          add(1, 2); //直接调用	//函数名就是函数的入口地址

          //定义一个函数类型
          {
                    typedef int(MyFuncType)(int a, int b); //定义了一个函数类型
                    MyFuncType *myPointerFunc = NULL;      //定义一个指针，指向某一种类的函数

                    myPointerFunc = &add; //细节
                    myPointerFunc(3, 4);  //间接调用

                    myPointerFunc = add; //细节
                    myPointerFunc(3, 4); //间接调用
          }

          //定义一个函数指针类型
          {
                    typedef (*MyPointerFuncType)(int a, int b);
                    MyPointerFuncType myPointerFunc; //定义一个指针
                    myPointerFunc = add;
                    myPointerFunc(5, 6);
          }

          //定义一个函数指针
          {
                    int (*MyPointerFunc)(int a, int b); //定义一个变量
                    MyPointerFunc = add;
                    MyPointerFunc(7, 8);
          }

          system("pause");
          return;
}

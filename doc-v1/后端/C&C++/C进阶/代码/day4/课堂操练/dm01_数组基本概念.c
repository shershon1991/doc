#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main11()
{
          int a[] = {1, 2};
          int b[100] = {1, 2, 3};
          int c[200] = {0};        //编译时，就已经确定，所有的值为0
          memset(c, 0, sizeof(c)); //显式地重置内存块
          /*
	C语言对一位数组规定：
	c是数组首元素的地址，说明c+1往后跳4个字节，即步长=4个字节
	&c是整个数组的地址，说明&c+1往后跳800个字节，即步长=800个字节
	*/
          system("pause");
          return;
}

//怎样表达int a[10]这种数据类型
//类型本质：固定大小内存块的别名
//定义数组类型
void main12()
{
          typedef int(MyArrayType)[5]; //定义了一个数据类型，数组数据类型
          int i = 0;
          MyArrayType myArray; //int myArray[5];

          for (i = 0; i < 5; i++)
          {
                    myArray[i] = i + 1;
          }

          for (i = 0; i < 5; i++)
          {
                    printf("%d ", myArray[i]);
          }

          printf("myArray:%d, myArray+1:%d \n", myArray, myArray + 1);
          printf("&myArray:%d, &myArray+1:%d \n", &myArray, &myArray + 1);

          system("pause");
          return;
}

//定义数组指针变量的方法
//1.第一种方法 数组类型 *
void main13()
{
          char *myArr[] = {"aaa", "bbb", "ccc"}; //指针数组

          //数组指针用一个指针来指向一个数组
          typedef int(MyArrayType)[5]; //定义了一个数组类型，数组数据类型
          int i = 0;
          MyArrayType myArray; //int myArray[5];//用类型定义变量

          MyArrayType *pArray; //定义一个指针变量，这个指针变量指向一个数组

          {
                    int a;
                    int *p = NULL;
                    p = &a;
          }

          {
                    int myArray2[5];    //相当于一级指针
                    pArray = &myArray2; //相当于二级指针
                    for (i = 0; i < 5; i++)
                    {
                              //myArray2[i] = i + 1;
                              (*pArray)[i] = i + 1;
                    }
                    for (i = 0; i < 5; i++)
                    {
                              printf("%d ", (*pArray)[i]);
                    }
          }

          system("pause");
          return;
}

//2.第二种方法
void main14()
{
          int i = 0;
          //定义声明一个数组指针类型
          typedef int(*pArrayType)[5];
          pArrayType pArray; //告诉编译器，给我分配一个指针变量

          int c[5];

          pArray = &c;

          for (i = 0; i < 5; i++)
          {
                    (*pArray)[i] = i + 1;
          }

          for (i = 0; i < 5; i++)
          {
                    printf("%d ", (*pArray)[i]);
          }

          system("pause");
          return;
}

//3.第三种方法
void main15()
{
          int(*pArray)[5]; //直接定义一个指向数组的 数组指针变量
          int c[5];
          int i = 0;
          pArray = &c;

          for (i = 0; i < 5; i++)
          {
                    (*pArray)[i] = i + 1;
          }

          for (i = 0; i < 5; i++)
          {
                    printf("%d ", (*pArray)[i]);
          }

          system("pause");
          return;
}
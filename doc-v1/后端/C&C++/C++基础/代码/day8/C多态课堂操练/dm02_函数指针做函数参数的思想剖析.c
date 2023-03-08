#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int myadd(int a, int b)
{
          printf("func add() do ... \n");
          return a + b;
}
int myadd2(int a, int b)
{
          printf("func add2() do ... \n");
          return a + b;
}
int myadd3(int a, int b)
{
          printf("func add3() do ... \n");
          return a + b;
}
int myadd4(int a, int b)
{
          printf("func add4() do ... \n");
          return a + b;
}

//定义了一个类型
typedef int (*MyTypeFuncAdd)(int a, int b);

//函数指针做函数参数1
int MainOp(MyTypeFuncAdd myFuncAdd)
{
          int c = myFuncAdd(5, 6);
          return c;
}

//函数指针做函数参数2
int MainOp2(int (*MyPointerFuncAdd)(int a, int b))
{
          int c = MyPointerFuncAdd(5, 6);
          return c;
}

//间接调用
void main201()
{
          /*
	MyTypeFuncAdd myFuncAdd = NULL;
	myadd(1, 2);	//直接调用

	myFuncAdd = myadd;	//间接调用
	myFuncAdd(3, 4);

	MainOp(myadd);
	MainOp2(myadd);
	*/

          //在mainop2没有发生变化的情况下，
          MainOp2(myadd2);
          MainOp2(myadd3);
          MainOp2(myadd4);

          system("pause");
          return;
}

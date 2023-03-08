#include <iostream>
using namespace std;

void myfunc41(int a)
{
          printf("a:%d \n", a);
}
void myfunc41(char *p)
{
          printf("%s \n", p);
}
void myfunc41(int a, int b)
{
          printf("a:%d \n", a);
}
void myfunc41(char *p1, char *p2)
{
          printf("p1:%s \n", p1);
          printf("p2:%s \n", p2);
}

//函数指针 基础的语法
//声明一个函数类型
//void myfunc41(int a, int b)
typedef void(myTypeFunc)(int a, int b);
//myTypeFunc* myfuncp = NULL;//定义一个函数指针，这个指针指向函数的入口地址

//声明一个函数指针类型
typedef void (*myPTypeFunc)(int a, int b); //声明了一个指针的数据类型
//myPTypeFunc fp = NULL;//通过函数指针类型，定义了一个函数指针

//定义一个函数指针变量
void (*myVarPTypeFunc)(int a, int b);

void main401()
{
          myPTypeFunc fp;
          fp = myfunc41;

          fp(1, 2);
          /*
	{
		char buf1[] = "aaaa";
		char buf2[] = "bbbb";
		fp(buf1, buf2);
	}
	*/

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;

//函数的业务逻辑一样
//函数的参数类型不一样
void myswap101(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswap102(char& a, char& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//让 类型参数化，方便程序员进行编码
//有，泛型编程
//template告诉C++编译器，我要开始泛型编程了，看到T不要随便报错
template <typename T>
void myswap1(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;

	cout << "我是模板函数，欢迎调用我" << endl;
}

void main101()
{
	{
		int x = 10;
		int y = 20;

		myswap101(x, y);
		printf("x:%d, y:%d \n", x, y);
	}
	
	{
		char a = 'a';
		char b = 'b';

		myswap102(a, b);
		printf("a:%c, b:%c \n", a, b);
	}

	cout << "hello..." << endl;
	system("pause");
	return;
}

//函数模板的调用
//1.显式类型调用
//2.自动类型推导
void main102()
{
	{
		int x = 10;
		int y = 20;

		myswap1<int>(x, y);	//显式类型调用
		//myswap1(x, y);			//自动类型推导
		printf("x:%d, y:%d \n", x, y);
	}

	{
		char a = 'a';
		char b = 'b';

		myswap1<char>(a, b);	//显式类型调用
		//myswap1(a, b);		//自动类型推导
		printf("a:%c, b:%c \n", a, b);
	}

	system("pause");
}

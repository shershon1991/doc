#include <iostream>
using namespace std;

//inline void printA();
//1.必须和函数体的实现，写在一块
inline void printA()
{
          int a = 10;
          cout << "a:" << a << endl;
}
void main101()
{
          printA();

          //2.C++编译器直接将函数体插入在函数调用的地方
          /*{
		int a = 10;
		cout << "a:" << a << endl;
	}*/

          cout << "hello..." << endl;
          system("pause");
          return;
}

//带参数的宏
#define MYFUNC(a, b) ((a) < (b) ? (a) : (b))
inline int myfunc(int a, int b)
{
          return a < b ? a : b;
}
int main102()
{
          int a = 1;
          int b = 3;
          //int c = myfunc(++a, b);
          int c = MYFUNC(++a, b);

          printf("a:%d \n", a);
          printf("b:%d \n", b);
          printf("c:%d \n", c);

          system("pause");
          return 0;
}

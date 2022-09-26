#include <iostream>
using namespace std;

void myswap301(int &a, int &b)
{
          int c = 0;
          c = a;
          a = b;
          b = c;
}
void myswap302(char &a, char &b)
{
          int c = 0;
          c = a;
          a = b;
          b = c;
}

template <typename T>
void myswap3(T &a, T &b)
{
          T c;
          c = a;
          a = b;
          b = c;

          cout << "我是模板函数，欢迎调用我" << endl;
}

void myswap3(int a, char c)
{
          cout << "a:" << a << "c:" << c << endl;
          cout << "我是普通函数，欢迎来访" << endl;
}

void main301()
{
          int a = 10;
          char c = 'z';

          myswap3(a, c); //普通函数的调用：可以进行隐式的类型转换
          myswap3(c, a);

          myswap3(a, a); //模板函数的调用（本质：类型参数化），将严格地按照类型进行匹配，不会进行自动类型转换

          cout << "hello..." << endl;
          system("pause");
          return;
}

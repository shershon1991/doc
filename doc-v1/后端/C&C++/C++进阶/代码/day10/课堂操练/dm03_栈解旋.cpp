#include <iostream>
using namespace std;

class Test3
{
public:
          Test3(int a, int b)
          {
                    this->a = a;
                    this->b = b;
                    cout << "构造函数执行\n";
          }
          ~Test3()
          {
                    cout << "析构函数执行\n";
          }

private:
          int a;
          int b;
};

//抛出的异常类型只能是所列出的类型
void myDivide3(int x, int y) throw(int, char, char *)
{
          Test3 t1(1, 2), t2(3, 4);
          cout << "myDivide要发生异常\n";
          //throw Test3;
          throw 1;
}
//可抛出任何类型
void myDivide302(int x, int y)
{
          Test3 t1(1, 2), t2(3, 4);
          cout << "myDivide要发生异常\n";
          throw 1;
}
//不抛出异常
void myDivide303(int x, int y) throw()
{
          Test3 t1(1, 2), t2(3, 4);
          cout << "myDivide要发生异常\n";
          throw 1;
}

void main301()
{
          try
          {
                    //myDivide3(1,2);
                    //myDivide302(1,2);
                    myDivide303(1, 2);
          }
          catch (int a)
          {
                    cout << "int类型异常\n";
          }
          catch (...)
          {
                    cout << "未知异常\n";
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

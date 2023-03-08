#include <iostream>
using namespace std;

class A
{
public:
          int a;
          int b;

          void get()
          {
                    cout << "b:" << b << endl;
          }
          void print()
          {
                    cout << "AAAAA" << endl;
          }
};

class B : public A
{
public:
          int b;

          void get_child()
          {
                    cout << "b:" << b << endl;
          }
          void print()
          {
                    cout << "BBBBB" << endl;
          }
};

//同名成员变量
void main701()
{
          B b1;
          b1.b = 1;
          b1.get_child();

          b1.A::b = 100;
          b1.get();

          b1.A::b = 200; //修改父类的b
          b1.get();

          b1.B::b = 2; //修改子类的b，默认情况下是B
          b1.get_child();

          cout << "hello..." << endl;
          system("pause");
          return;
}

//同名成员函数
void main702()
{
          B b1;
          b1.print();
          b1.A::print();

          b1.B::print();
          b1.A::print();

          cout << "hello..." << endl;
          system("pause");
          return;
}
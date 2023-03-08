#include <iostream>
using namespace std;

class A
{
public:
          static int a;
          int b;
          A()
          {
                    cout << "A的构造函数" << endl;
          }
          void get()
          {
                    cout << "b:" << b << endl;
          }
          void print()
          {
                    cout << "AAAAA" << endl;
          }
};

int A::a = 100; //这句话不是简单地变量赋值，更重要的是告诉C++编译器，你要给我分配内存，我在继承类中需要用到

class B : private A
{
public:
          int b;
          B()
          {
                    cout << "B的构造函数" << endl;
          }
          void get_child()
          {
                    cout << "b:" << b << endl;
                    cout << a << endl;
          }
          void print()
          {
                    cout << "BBBBB" << endl;
          }
};

//1.static关键字遵守派生类的访问控制规则
//2.不是简单地变量赋值，更重要的是告诉C++编译器，你要给我分配内存，我在继承类中需要用到
//3.A类中添加构造函数
//构造函数默认是私有的
void main801()
{
          //B b1;
          //b1.a = 200;	//err

          cout << "hello..." << endl;
          system("pause");
          return;
}

void main802()
{
          A a1;
          a1.print();

          B b1;
          b1.get_child();

          system("pause");
}
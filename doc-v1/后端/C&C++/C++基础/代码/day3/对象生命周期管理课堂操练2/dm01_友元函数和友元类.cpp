#include <iostream>
using namespace std;

class A
{
public:
          friend class B;                     //类B是类A的好朋友，在B中可以访问类A的私有属性、私有方法
          friend void modifyA(A *pA, int _a); //modifyA是类A的好朋友，声明的位置与访问控制修饰符没有关系

          A(int a = 0, int b = 0)
          {
                    this->a = a;
                    this->b = b;
          }
          int getA()
          {
                    return this->a;
          }

private:
          int a;
          int b;
};

void modifyA(A *pA, int _a)
{
          //pA->a = 100;
          pA->a = _a;
}

class B
{
public:
          void Set(int a)
          {
                    Aobject.a = a;
          }
          void printA()
          {
                    cout << Aobject.a << endl;
          }

private:
          A Aobject;
};

void main101()
{
          A a1(1, 2);
          cout << a1.getA() << endl;

          modifyA(&a1, 300);
          cout << a1.getA() << endl;

          cout << "hello..." << endl;
          system("pause");
          return;
}

void main102()
{
          B b1;
          b1.Set(300);
          b1.printA();

          system("pause");
}
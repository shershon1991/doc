#include <iostream>
using namespace std;

class Interface1
{
public:
          virtual int add(int a, int b) = 0;
          virtual void print() = 0;
};

class Interface2
{
public:
          virtual int mult(int a, int b) = 0;
          virtual void print() = 0;
};

class Parent7
{
public:
          int getA()
          {
                    a = 0;
                    return a;
          }

private:
          int a;
};

class Child7 : public Parent7, public Interface1, public Interface2
{
public:
          virtual int add(int a, int b)
          {
                    cout << "Child7:add()函数执行" << endl;
                    return a + b;
          }
          virtual void print()
          {
                    cout << "Child7:print()函数执行" << endl;
          }
          virtual int mult(int a, int b)
          {
                    cout << "Child7:mult()函数执行" << endl;
                    return a * b;
          }
};

void main701()
{
          Child7 c1;
          c1.print();

          Interface1 *it1 = &c1;
          it1->add(1, 2);

          Interface2 *it2 = &c1;
          it2->mult(1, 2);

          cout << "hello..." << endl;
          system("pause");
          return;
}

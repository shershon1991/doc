#include <iostream>
using namespace std;

//构造函数中调用虚函数，能发生多态吗
class Parent3
{
public:
          Parent3(int a = 0)
          {
                    this->a = a;
                    print();
          }

          virtual void print()
          {
                    cout << "我是爹..." << endl;
          }

private:
          int a;
};

class Child3 : public Parent3
{
public:
          Child3(int a = 0, int b = 0) : Parent3(a)
          {
                    this->b = b;
                    print();
          }

          virtual void print()
          {
                    cout << "我是儿..." << endl;
          }

private:
          int b;
};

void howToPrint(Parent3 *base)
{
          base->print();
}

void main301()
{
          Child3 c1; //创建一个子类对象，在这个过程中，在父类构造函数中调用虚函数print,能发生多态吗

          cout << "hello..." << endl;
          system("pause");
          return;
}

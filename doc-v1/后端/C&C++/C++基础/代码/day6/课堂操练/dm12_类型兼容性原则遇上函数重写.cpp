#include <iostream>
using namespace std;

class Parent12
{
public:
          Parent12(int a)
          {
                    this->a = a;
                    cout << "Parent12 a" << a << endl;
          }
          virtual void print()
          {
                    cout << "Parent12 打印a" << a << endl;
          }

private:
          int a;
};

class Child12 : public Parent12
{
public:
          Child12(int b) : Parent12(10)
          {
                    this->b = b;
                    cout << "Child12 b" << b << endl;
          }
          virtual void print() //virtual 父类写了virtual，子类可写可不写
          {
                    cout << "Child12 打印b" << b << endl;
          }

private:
          int b;
};

void howToPrint12(Parent12 *base)
{
          base->print(); //一种调用语句 有多种表现形态...
}

void howToPrint122(Parent12 &base)
{
          base.print();
}

void main1201()
{
          Parent12 *base = NULL;
          Parent12 p1(20);
          Child12 c1(30);

          base = &p1;
          base->print(); //执行父类的打印函数

          base = &c1;
          base->print(); //执行谁的函数？	//面向对象新需求

          {
                    Parent12 &base2 = p1;
                    base2.print();

                    Parent12 &base3 = c1; //base3是c1的别名
                    base3.print();
          }

          //函数调用
          howToPrint12(&p1);
          howToPrint12(&c1);

          howToPrint122(p1);
          howToPrint122(c1);

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;

//多态成立的3个条件
//1.要有继承 2.虚函数重写 3.父类指针（父类引用）指向子类对象

class Parent
{
public:
          Parent(int a = 0)
          {
                    this->a = a;
          }

          virtual void print()
          {
                    cout << "我是爹..." << endl;
          }

private:
          int a;
};

class Child : public Parent
{
public:
          Child(int a = 0, int b = 0) : Parent(a)
          {
                    this->b = b;
          }

          virtual void print() //1.动手脚 写virtual 会特殊处理
          {
                    cout << "我是儿..." << endl;
          }

private:
          int b;
};

void howToPrint(Parent *base)
{
          base->print(); //会有多态发生	//2.动手脚
                         //效果：传来父类对象，执行父类的print函数，传来子类对象，执行子类的print函数
                         //C++编译器根本不需要区分是子类对象还是父类对象
                         //父类和子类对象分别有vptr指针===》虚函数表===》函数的入口地址
                         //迟邦定(在运行时，C++编译器才去判断)
}

void main101()
{
          Parent p1; //3.动手脚 提前布局
                     //用类定义对象的时候，C++编译器会在对象中添加一个vptr指针
          Child c1;  //子类里面也有一个vptr指针

          howToPrint(&p1);
          howToPrint(&c1);

          cout << "hello..." << endl;
          system("pause");
          return;
}

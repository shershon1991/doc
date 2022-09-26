#include <iostream>
using namespace std;

class Parent4
{
public:
          void printP()
          {
                    cout << "我是爹..." << endl;
          }

private:
          int a;
};

class Child4 : public Parent4
{
public:
          void printC()
          {
                    cout << "我是儿..." << endl;
          }
};

/*
兼容规则中所指的替代包括以下情况：
子类对象可以当做父类对象使用
子类对象可以直接赋值给父类对象
子类对象可以直接初始化父类对象
父类指针可以直接指向子类对象
父类引用可以直接引用子类对象
*/
void howToPrint(Parent4 *base)
{
          base->printP(); //父类的成员函数
}
void howToPrint(Parent4 &base)
{
          base.printP(); //父类的成员函数
}
void main401()
{
          Parent4 p1;
          p1.printP();

          Child4 c1;
          c1.printC();
          c1.printP();

          //赋值兼容性原则
          //1-1.基类指针（引用）指向 子类对象
          Parent4 *p = NULL;
          p = &c1;
          p->printP();

          //1-2.指针做函数参数
          howToPrint(&p1);
          howToPrint(&c1);

          //1-3.引用作函数参数
          howToPrint(p1);
          howToPrint(c1);

          //2.第2层含义
          //可以让子类对象初始化父类对象
          //子类是一种特殊的父类
          Parent4 p3 = c1;

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;

class B
{
public:
          int b;
          B()
          {
                    cout << "B构造函数" << endl;
          }
};

class B1 : virtual public B
{
public:
          int b1;
};

class B2 : public B
{
public:
          int b2;
};

class C : public B1, public B2
{
public:
          int c;
};

void main1101()
{
          C c1;
          c1.b1 = 100;
          c1.b2 = 100;
          c1.c = 300;
          //c1.b = 400;	//继承的二义性和虚继承解决方案

          cout << "hello..." << endl;
          system("pause");
          return;
}

class D1
{
public:
          int k;
};

class D2
{
public:
          int k;
};

class E : public D1, public D2
{
};

void main1102()
{
          E e1;
          e1.D1::k = 100;
          e1.D2::k = 200;

          system("pause");
}

void main1103()
{
          cout << sizeof(B) << endl;  //4
          cout << sizeof(B1) << endl; //12	加上virtual关键字后，C++编译器会给变量偷偷地增加属性
          cout << sizeof(B2) << endl; //8
          //cout << sizeof(C) << endl;

          system("pause");
}
#include <iostream>
using namespace std;

class Complex3
{
private:
          int a;
          int b;
          //friend void operator<<(ostream& out, Complex3& c1);
          friend ostream &operator<<(ostream &out, Complex3 &c1);

public:
          Complex3(int a = 0, int b = 0)
          {
                    this->a = a;
                    this->b = b;
          }
          void printCom()
          {
                    cout << a << " + " << b << "i" << endl;
          }

public:
          Complex3 &operator++()
          {
                    this->a++;
                    this->b++;
                    return *this;
          }
          Complex3 operator++(int)
          {
                    //先赋值，后运算
                    Complex3 tmp = *this;
                    this->a++;
                    this->b++;
                    return tmp;
          }
          Complex3 operator+(Complex3 &c2)
          {
                    Complex3 tmp(this->a + c2.a, this->b + c2.b);
                    return tmp;
          }
          Complex3 operator-(Complex3 &c2)
          {
                    Complex3 tmp(this->a - c2.a, this->b - c2.b);
                    return tmp;
          }
          Complex3 &operator--()
          {
                    this->a--;
                    this->b--;
                    return *this;
          }
          Complex3 operator--(int)
          {
                    Complex3 tmp = *this;
                    this->a--;
                    this->b--;
                    return tmp;
          }
};

void main301()
{
          Complex3 c1(1, 2), c2(3, 4);

          //1.全局函数方法实现 + 运算符重载
          //Complex2 operator+(Complex2 &c1, Complex2 &c2);
          Complex3 c3 = c1 + c2;
          c3.printCom();

          //2.成员函数方法实现 - 运算符重载
          //c1.operator-(this, c2);
          //Complex2 operator-(Complex2 & c2);
          Complex3 c4 = c1 - c2;
          c4.printCom();

          //前置++操作符，用全局函数实现
          ++c1;
          c1.printCom();

          //前置--操作符，成员函数方法
          --c1;
          c1.printCom();

          //后置++操作符，用全局函数实现
          c1++;
          c1.printCom();

          //后置--操作符，成员函数方法
          c1--;
          c1.printCom();

          cout << "hello..." << endl;
          system("pause");
          return;
}

/*
void operator<<(ostream& out, Complex3& c1)
{
	out << c1.a << " + " << c1.b << "i" << endl;
}
*/

ostream &operator<<(ostream &out, Complex3 &c1)
{
          out << c1.a << " + " << c1.b << "i" << endl;
          return out;
}

void main302()
{
          int a = 10;

          Complex3 c1(1, 2), c2(3, 4);
          cout << a << endl; //按照数据类型

          //1
          cout << c1;
          //2 ostream类中添加成员函数，不行
          //拿不到ostream的源码，所以只能使用使用全局函数去实现
          //cout.operator<<(c1);

          //2 函数返回值当左值，需要返回一个引用
          cout << c1 << "sadasda";
          //cout.operator<<(c1).operator<<("sadasda")

          system("pause");
}
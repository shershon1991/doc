#include <iostream>
using namespace std;

class Complex2
{
private:
          int a;
          int b;
          friend Complex2 operator+(Complex2 &c1, Complex2 &c2);
          friend Complex2 &operator++(Complex2 &c1);
          friend Complex2 operator++(Complex2 &c1, int);

public:
          Complex2(int a = 0, int b = 0)
          {
                    this->a = a;
                    this->b = b;
          }
          void printCom()
          {
                    cout << a << " + " << b << "i" << endl;
          }

public:
          //2.成员函数方法实现减号运算符重载
          Complex2 operator-(Complex2 &c2)
          {
                    Complex2 tmp(this->a - c2.a, this->b - c2.b);
                    return tmp;
          }
          Complex2 &operator--()
          {
                    this->a--;
                    this->b--;
                    return *this;
          }
          Complex2 operator--(int)
          {
                    Complex2 tmp = *this;
                    this->a--;
                    this->b--;
                    return tmp;
          }
};

Complex2 &operator++(Complex2 &c1)
{
          c1.a++;
          c1.b++;
          return c1;
}

Complex2 operator++(Complex2 &c1, int)
{
          //先赋值，后运算
          Complex2 tmp = c1;
          c1.a++;
          c1.b++;
          return tmp;
}

//1.全局函数方法实现 + 运算符重载
Complex2 operator+(Complex2 &c1, Complex2 &c2)
{
          Complex2 tmp(c1.a + c2.a, c1.b + c2.b);
          return tmp;
}

void main201()
{
          Complex2 c1(1, 2), c2(3, 4);

          //1.全局函数方法实现 + 运算符重载
          //Complex2 operator+(Complex2 &c1, Complex2 &c2);
          Complex2 c3 = c1 + c2;
          c3.printCom();

          //2.成员函数方法实现 - 运算符重载
          //c1.operator-(this, c2);
          //Complex2 operator-(Complex2 & c2);
          Complex2 c4 = c1 - c2;
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

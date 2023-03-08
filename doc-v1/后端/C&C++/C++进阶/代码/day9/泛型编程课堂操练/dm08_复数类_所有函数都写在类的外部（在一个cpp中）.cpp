#include <iostream>
using namespace std;

template <typename T>
class Complex8
{
          //friend Complex8 MySub(Complex8& c1, Complex8& c2);
          friend ostream &operator<<<T>(ostream &out, Complex8 &c3);

public:
          Complex8(T a, T b);
          void printCom();
          Complex8 operator+(Complex8 &c2);

private:
          T a;
          T b;
};

//构造函数写在了类的外面
template <typename T>
Complex8<T>::Complex8(T a, T b)
{
          this->a = a;
          this->b = b;
}

template <typename T>
void Complex8<T>::printCom()
{
          cout << a << " + " << b << "i" << endl;
}

//成员函数实现+运算符重载
template <typename T>
Complex8<T> Complex8<T>::operator+(Complex8<T> &c2)
{
          //Complex8<T> tmp(a + c2.a, b + c2.b);
          Complex8 tmp(a + c2.a, b + c2.b);
          return tmp;
}

//友元函数实现<<运算符重载
template <typename T>
ostream &operator<<(ostream &out, Complex8<T> &c3)
{
          out << c3.a << " + " << c3.b << "i" << endl;
          return out;
}

//滥用友元函数
/*
template <typename T>
Complex8<T> MySub(Complex8<T>& c1, Complex8<T>& c2)
{
	Complex8 tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
*/

void main801()
{
          Complex8<int> c1(1, 2);
          Complex8<int> c2(3, 4);

          Complex8<int> c3 = c1 + c2;
          //Complex8 operator+(Complex8 &c2)

          cout << c3 << endl;
          //ostream &operator<<(ostream &out, Complex8 &c3)

          //滥用友元函数
          {
                    //Complex8<int> c4 = MySub(c1, c2);
                    //Complex8 MySub(Complex8 &c1, Complex8 &c2)
                    //cout << c4 << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

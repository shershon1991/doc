#include <iostream>
using namespace std;

template <typename T>
class Complex7
{
          friend Complex7 MySub(Complex7 &c1, Complex7 &c2)
          {
                    Complex7 tmp(c1.a - c2.a, c1.b - c2.b);
                    return tmp;
          }
          friend ostream &operator<<(ostream &out, Complex7 &c3)
          {
                    out << c3.a << " + " << c3.b << "i" << endl;
                    return out;
          }

public:
          Complex7(T a, T b)
          {
                    this->a = a;
                    this->b = b;
          }
          Complex7 operator+(Complex7 &c2)
          {
                    Complex7 tmp(a + c2.a, b + c2.b);
                    return tmp;
          }
          void printCom()
          {
                    cout << a << " + " << b << "i" << endl;
          }

private:
          T a;
          T b;
};

//运算符重载的正规写法
//重载 << >> 只能用友元函数，其他的运算符重载都要写成成员函数，不要滥用友元函数
/*
ostream& operator<<(ostream& out, Complex& c3)
{
	out << "a:" << c3.a << " b:" << c3.b << endl;
	return out;
}
*/

void main701()
{
          Complex7<int> c1(1, 2);
          Complex7<int> c2(3, 4);

          Complex7<int> c3 = c1 + c2;
          //Complex7 operator+(Complex7 &c2)

          cout << c3 << endl;
          //ostream& operator<<(ostream& out, Complex7& c3)

          //滥用友元函数
          {
                    Complex7<int> c4 = MySub(c1, c2);
                    //Complex7 MySub(Complex7 &c1, Complex7 &c2)
                    cout << c4 << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

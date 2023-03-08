#include <iostream>
using namespace std;
#include "dm09_complex.h"

template <typename T>
Complex9<T>::Complex9(T a, T b)
{
          this->a = a;
          this->b = b;
}

template <typename T>
void Complex9<T>::printCom()
{
          cout << a << " + " << b << "i" << endl;
}

template <typename T>
Complex9<T> Complex9<T>::operator+(Complex9<T> &c2)
{
          //Complex9<T> tmp(a + c2.a, b + c2.b);
          Complex9 tmp(a + c2.a, b + c2.b);
          return tmp;
}

template <typename T>
ostream &operator<<(ostream &out, Complex9<T> &c3)
{
          out << c3.a << " + " << c3.b << "i" << endl;
          return out;
}

//滥用友元函数
/*
template <typename T>
Complex9<T> MySub(Complex9<T> & c1, Complex9<T> & c2)
{
	Complex9 tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
*/
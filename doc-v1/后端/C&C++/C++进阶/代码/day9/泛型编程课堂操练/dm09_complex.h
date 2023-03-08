#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Complex9
{
	//friend Complex9 MySub(Complex9& c1, Complex9& c2);
	friend ostream& operator<< <T>(ostream& out, Complex9& c3);
public:
	Complex9(T a, T b);
	void printCom();
	Complex9 operator+(Complex9& c2);
private:
	T a;
	T b;
};

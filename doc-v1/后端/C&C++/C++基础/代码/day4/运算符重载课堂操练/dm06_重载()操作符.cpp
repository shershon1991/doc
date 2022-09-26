#include <iostream>
using namespace std;

class F {
public:
	int operator()(int a, int b)
	{
		return a * a + b * b;
	}
private:
};

class F2 {
public:
	int MemFunc(int a, int b)
	{
		return a * a + b * b;
	}
private:
};

void main601()
{
	F f;
	f(2, 4);
	//int operator()(int a, int b)

	F2 f2;
	f2.MemFunc(2, 4);
	

	cout << "hello..." << endl;
	system("pause");
	return;
}

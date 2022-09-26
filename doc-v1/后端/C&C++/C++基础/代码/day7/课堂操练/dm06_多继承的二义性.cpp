#include <iostream>
using namespace std;

class B
{
public:
	int b;
};

class B1 : virtual public B
{
public:
	int b1;
};

class B2 : virtual public B
{
public:
	int b2;
};

class C : public B1, public B2
{
public:
	int c;
};

void main601()
{
	C myc;
	myc.c = 10;
	myc.b = 20;

	cout << "hello..." << endl;
	system("pause");
	return;
}

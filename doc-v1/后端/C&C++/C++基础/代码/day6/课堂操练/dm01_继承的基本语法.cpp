#include <iostream>
using namespace std;

class Parent
{
public:
	void print()
	{
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}
public:
	int a;
	int b;
};

//class Child : protected Parent 
//class Child : private Parent
class Child : public Parent
{
private:
	int c;
};

void main101()
{
	Child c1;
	//c1.c = 1;
	c1.a = 2;
	c1.b = 3;
	c1.print();

	cout << "hello..." << endl;
	system("pause");
	return;
}

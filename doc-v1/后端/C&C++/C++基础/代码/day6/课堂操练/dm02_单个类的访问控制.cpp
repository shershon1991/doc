#include <iostream>
using namespace std;

//public	在类的内部和外部都能使用
//protected	在类的内部使用，在继承的子类中可以使用
//private	只能在类的内部使用，不能在类的外部使用
class Parent2
{
public:
	int a;
	void printT()
	{
		cout << "printT " << endl;
	}
protected:
	int b;
private:
	int c;
};

//公有继承
class Child2 : public Parent2
{
public:
	void useVar()
	{
		a = 0;//ok
		b = 0;//ok
		//c = 0;//err
	}
};

/*
  看调用语句，这句话写在子类的内部、外部
看子类如何从父类继承（public / protected / private）
看父类中的访问级别（public / protected / private）
*/
void main201()
{
	Parent2 t1, t2;
	t1.a = 1;//ok
	//t1.b = 2;//err
	//t2.c = 3;//err

	cout << "hello..." << endl;
	system("pause");
	return;
}

//私有继承
class Child22 : private Parent2
{
public:
	void useVar()
	{
		a = 0;//ok
		b = 0;//ok
		//c = 0;//err
	}
};

void main202()
{
	Child22 c2;
	//c2.a = 1;//err
	//c2.b = 2;//err
	//c2.c = 3;//err

	cout << "hello..." << endl;
	system("pause");
	return;
}

//保护继承
class Child23 : protected Parent2
{
public:
	void useVar()
	{
		a = 0;//ok
		b = 0;//ok
		//c = 0;//err
	}
};

void main203()
{
	Child23 c3;
	//c3.a = 1;//err
	//c3.b = 2;//err
	//c3.c = 3;//err 

	cout << "hello..." << endl;
	system("pause");
	return;
}
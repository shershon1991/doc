#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "MyVector.cpp"

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		m_p = new char[1];
		strcpy(m_p, "");
	}
	Teacher(char* name, int age)
	{
		this->age = age;
		m_p = new char[strlen(name) + 1];
		strcpy(m_p, name);
	}
	Teacher(const Teacher& obj)
	{
		m_p = new char[strlen(obj.m_p) + 1];
		strcpy(m_p, obj.m_p);
		age = obj.age;
	}
	~Teacher()
	{
		if (m_p != NULL)
		{
			delete[] m_p;
			m_p = NULL;
		}
	}
	void printT()
	{
		cout << m_p << ", " << age << endl;
	}

	friend ostream& operator<<(ostream& out, Teacher& t);
	Teacher& operator=(const Teacher& obj)
	{
		if (m_p != NULL)
		{
			delete[] m_p;
			m_p = NULL;
			age = 33;
		}
		m_p = new char[strlen(obj.m_p) + 1];
		age = obj.age;
		strcpy(m_p, obj.m_p);
		return *this;
	}
private:
	int age;
	//char name[32];
	char* m_p;
};

ostream& operator<<(ostream& out, Teacher& t)
{
	out << t.m_p << ", " << t.age << endl;
	return out;
}

void main4()
{
	char str1[] = "t1";
	char str2[] = "t2";
	char str3[] = "t3";
	char str4[] = "t4";

	Teacher t1(str1, 31), t2(str2, 32), t3(str3, 33), t4(str4, 34);
	MyVector<Teacher *> tArray(4);
	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;
	tArray[3] = &t4;
	for (int i = 0; i < 4; i++)
	{
		Teacher *tmp = tArray[i];
		tmp->printT();
	}

	system("pause");
	return;
}

void main3()
{
	char str1[] = "t1";
	char str2[] = "t2";
	char str3[] = "t3";
	char str4[] = "t4";

	Teacher t1(str1, 31), t2(str2, 32), t3(str3, 33), t4(str4, 34);
	MyVector<Teacher> tArray(4);
	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;
	for (int i = 0; i < 4; i++)
	{
		Teacher tmp = tArray[i];
		tmp.printT();
	}

	system("pause");
	return;
}

void main2()
{
	MyVector<char> myv1(10);

	myv1[0] = 'a';
	myv1[1] = 'b';
	myv1[2] = 'c';
	myv1[3] = 'd';
	myv1[4] = 'e';

	cout << myv1;
	system("pause");
	return;
}

void main1()
{
	MyVector<int> myv1(10);
	for (int i = 0; i < myv1.getLen(); i++)
	{
		myv1[i] = i + 1;
		cout << myv1[i] << " ";
	}
	cout << endl;

	MyVector<int> myv2 = myv1;
	for (int i = 0; i < myv2.getLen(); i++)
	{
		cout << myv2[i] << " ";
	}
	cout << myv2 << endl;	//ostream &operator<<(ostream &out, const MyVector &obj)

	cout << "hello..." << endl;
	system("pause");
	return;
}

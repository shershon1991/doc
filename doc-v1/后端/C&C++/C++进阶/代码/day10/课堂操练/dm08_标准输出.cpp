#include <iostream>
using namespace std;

void main801()
{
	cout << "hello..." << endl;
	cout.put('h').put('e').put('l');

	const char* p = "hello itcast";
	cout.write(p, strlen(p)) << endl;
	cout.write(p, strlen(p) - 4) << endl;;
	cout.write(p, strlen(p) + 4) <<endl;
	
	system("pause");
	return;
}

void main802()
{
	cout << "<start>";
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase);
	cout.setf(ios::internal);
	cout << hex << 123 << "<end>\n";

	system("pause");
	return;
}
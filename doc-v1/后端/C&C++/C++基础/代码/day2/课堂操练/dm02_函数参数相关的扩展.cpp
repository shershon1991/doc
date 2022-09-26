#include <iostream>
using namespace std;

void myPrint21(int x = 2)
{
          cout << "x:" << x << endl;
}
void myPrint22(int m, int n, int x = 2, int y = 3)
{
          cout << "x:" << x << endl;
}

//1.若填写使用填写的值，未填写使用默认
//2.默认参数规则：若出现默认参数，那么形参右边都必须是默认参数
void main201()
{
          myPrint21();
          myPrint21(4);

          cout << "hello..." << endl;
          system("pause");
          return;
}

//函数占位参数，函数调用时，必须写够参数
void func21(int a, int b, int)
{
          cout << "a:" << a << ",b:" << b << endl;
}
void main202()
{
          //func21(1, 2); //err
          func21(1, 2, 3);

          cout << "hello..." << endl;
          system("pause");
          return;
}

//默认参数和占位参数
void func22(int a, int b, int = 0)
{
          cout << "a:" << a << ",b:" << b << endl;
}
void main203()
{
          func22(1, 2);    //ok
          func22(1, 2, 3); //ok

          cout << "hello..." << endl;
          system("pause");
          return;
}

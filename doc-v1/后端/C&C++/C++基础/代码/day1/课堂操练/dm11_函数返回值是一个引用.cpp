#include <iostream>
using namespace std;

int getA111()
{
          int a;
          a = 10;
          return a;
}
int &getA112()
{
          int a;
          a = 10;
          return a;
}
int *getA113()
{
          int a;
          a = 10;
          return &a;
}

//若返回栈变量
//不能成为其他引用的初始值
//不能作为左值使用
void main1101()
{
          int a1 = getA111();
          int a2 = getA112();
          int &a3 = getA112();

          printf("a1:%d, a2:%d, a3:%d \n", a1, a2, a3);

          cout << "hello..." << endl;
          system("pause");
          return;
}

int j111()
{
          static int a = 10;
          a++;
          return a;
}
int &j112()
{
          static int a = 10;
          a++;
          return a;
}
//若返回静态变量或全局变量
//可以称为其它引用的初始值
//即可作为右值使用，也可作为左值使用
void main1102()
{
          int a1 = 10;
          int a2 = 10;

          a1 = j111();
          a2 = j112();
          int &a3 = j112();

          printf("a1:%d \n", a1);
          printf("a2:%d \n", a2);
          printf("a3:%d \n", a3);

          system("pause");
}

//返回变量的值
int g111()
{
          static int a = 10;
          a++;
          return a;
}
//返回变量本身
int &g112()
{
          static int a = 10;
          a++;
          return a;
}
void main1103()
{
          //g111() = 100;
          g112() = 100;

          system("pause");
}

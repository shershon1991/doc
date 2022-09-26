#include <iostream>
using namespace std;

void myPrint31(int a)
{
          printf("a:%d \n", a);
}
void myPrint31(char *p)
{
          printf("%s \n", p);
}
void myPrint31(int a, int b)
{
          printf("a:%d \n", a);
          printf("b:%d \n", b);
}

//当函数名和不同的参数搭配时函数的含义不同
//名称相同，参数不同（个数，类型，顺序）
void main301()
{
          char *p = NULL;
          char name[64] = "abdsdsbad";

          myPrint31(1);
          p = name;
          myPrint31(p);
          myPrint31(1, 2);

          cout << "hello..." << endl;
          system("pause");
          return;
}

//函数默认参数和函数重载在一起
void myPrint32(int a, int b, int c = 0)
{
          printf("a:%d \n", a);
          printf("b:%d \n", b);
}
void myPrint32(int a, int b)
{
          printf("a:%d \n", a);
          printf("b:%d \n", b);
}
void myPrint32(int a)
{
          printf("a:%d \n", a);
}
void main302()
{
          //myPrint32(1, 2);//err 存在二义性
          myPrint32(1);

          cout << "hello..." << endl;
          system("pause");
          return;
}

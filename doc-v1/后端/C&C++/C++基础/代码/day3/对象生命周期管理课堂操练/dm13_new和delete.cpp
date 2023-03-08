#include <iostream>
using namespace std;

//1.new		delete	操作符是C++的语法
//	malloc	free	函数是C语言的函数
//2.new 基础类型变量 分配数组变量 分配类对象
//3.

//分配基础类型
void main1301()
{
          int *p = (int *)malloc(sizeof(int));
          *p = 10;
          free(p);

          int *p2 = new int;
          *p2 = 20;
          delete p2;

          int *p3 = new int(30);
          printf("*p3:%d \n", *p3);
          delete p3;

          cout << "hello..." << endl;
          system("pause");
          return;
}

//分配数组变量
void main1302()
{
          int *p = (int *)malloc(sizeof(int) * 10); //int array[10]
          p[0] = 1;
          free(p);

          int *pArray = new int[10];
          pArray[2] = 1;
          delete[] pArray;

          cout << "hello..." << endl;
          system("pause");
          return;
}

//分配类对象
//区别：new会自动执行类型的构造函数，delete会自动执行类的析构函数
class Test13
{
public:
          Test13(int _a)
          {
                    a = _a;
                    cout << "构造函数执行" << endl;
          }
          ~Test13()
          {
                    cout << "析构函数执行" << endl;
          }

private:
          int a;
};
void main1303()
{
          Test13 *pT1 = (Test13 *)malloc(sizeof(Test13));
          free(pT1);

          Test13 *pT2 = new Test13(10);
          delete pT2;

          cout << "hello..." << endl;
          system("pause");
          return;
}
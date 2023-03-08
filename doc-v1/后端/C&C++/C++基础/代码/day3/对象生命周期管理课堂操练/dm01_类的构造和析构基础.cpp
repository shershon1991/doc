#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Test
{
public:
          Test() //无返回类型的声明 构造函数
          {
                    a = 10;
                    p = (char *)malloc(100);
                    strcpy(p, "aaaaaadd");
                    cout << "我是构造函数，被调用了" << endl;
          }
          ~Test() //无参数，无返回类型的声明 析构函数
          {
                    if (p != NULL)
                    {
                              free(p);
                    }
                    cout << "我是析构函数，被调用了" << endl;
          }
          void print()
          {
                    cout << "p:" << p << endl;
                    cout << "a:" << a << endl;
          }

private:
          int a;
          char *p;
};

//给对象搭建一个舞台，研究对象的行为
void objplay()
{
          //先创建的对象后释放
          Test t1, t2;
          t1.print();

          printf("分隔符 \n");
          t2.print();
}

void main101()
{
          objplay();

          cout << "hello..." << endl;
          system("pause");
          return;
}

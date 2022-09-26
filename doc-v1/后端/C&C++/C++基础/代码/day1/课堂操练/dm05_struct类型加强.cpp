#include <iostream>
using namespace std;

//struct关键字和class关键字 完成的功能是一样的
//区别后面介绍 抛砖
class c1
{
public:
protected:
private:
};

struct Teacher
{
public:
          char name[32];
          int age;

protected:
          int a;
};
void main501()
{
          Teacher t1;
          t1.age = 28;

          system("pause");
}

//C++中所有的变量和函数都必须有类型
//C语言中的默认类型在C++中是不合法的
//函数f的返回值是什么类型，参数又是什么类型？
//函数g可以接收多少个参数？
//更换成.cpp试试
int f(int i)
{
          printf("i:%d \n", i);
          return 0;
}
int g(int a, int b, int c, int d, int e)
{
          return 5;
}
int main502(int argc, char *argv[])
{
          f(10);
          printf("g() = %d\n", g(1, 2, 3, 4, 5));

          getchar();
          return 0;
}
#include <iostream>
using namespace std;

//类模板的定义
//类模板的使用
//类模板做函数参数

//模板类 类型参数化
template <typename T>
class A
{
public:
          A(T a = 0)
          {
                    this->a = a;
          }
          void printA()
          {
                    cout << "a:" << a << endl;
          }

protected:
          T a;
};

//从模板类派生普通类
//子模板派生时，需要具体化模板类，C++编译器需要知道父类的数据类型是什么样子的
//===>要知道父类所占的内存大小是多少，只有数据类型固定下来，才知道如何分配内存
class B : public A<int>
{
public:
          B(int a = 10, int b = 20) : A<int>(a)
          {
                    this->b = b;
          }
          void printB()
          {
                    cout << "a:" << a << " b:" << b << endl;
          }

private:
          int b;
};

template <typename T>
class C : public A<T>
{
public:
          C(T c, T a) : A<T>(a)
          {
                    this->c = c;
          }
          void printC()
          {
                    cout << "a:" << this->a << " c:" << c << endl;
          }

protected:
          T c;
};

//从模板类派生模板类
void main603()
{
          C<int> c1(1, 2);
          c1.printC();

          system("pause");
}

void main602()
{
          B b1(1, 2);
          b1.printB();

          system("pause");
}

//类模板做函数参数
void useA(A<int> &a)
{
          a.printA();
}

void main601()
{
          //模板类（本身就是类型化的）===> 具体的类 ===> 定义具体的变量
          A<int> a1(11), a2(20), a3(30); //模板类是抽象的 ==> 需要进行类型具体化
          //a1.printA();

          useA(a1);
          useA(a2);
          useA(a3);

          cout << "hello..." << endl;
          system("pause");
          return;
}

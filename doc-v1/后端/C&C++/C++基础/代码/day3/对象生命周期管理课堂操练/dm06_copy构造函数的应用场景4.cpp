#include <iostream>
using namespace std;

class Location2
{
public:
          Location2(int xx = 0, int yy = 0)
          {
                    X = xx;
                    Y = yy;
                    cout << "Constructor Object.\n";
          }
          Location2(const Location2 &obj) //copy构造函数
          {
                    X = obj.X;
                    Y = obj.Y;
                    cout << "调用copy构造函数.\n";
          }
          ~Location2()
          {
                    cout << X << ", " << Y << " Object destroyed." << endl;
          }
          int GetX()
          {
                    return X;
          }
          int GetY()
          {
                    return Y;
          }

private:
          int X, Y;
};

void f(Location2 p)
{
          cout << p.GetX() << endl;
}

//g函数 返回一个元素
//结论1：函数的返回值是一个元素（复杂类型的），返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数）
//结论2：匿名对象的去和留
//如果用匿名对象初始化 另外一个同类型的对象，匿名对象转成有名对象
//如果用匿名对象赋值给 另外一个同类型的对象，匿名对象被析构

//你这么写代码，设计编译器的大牛们：
//就给你返回一个新对象（没有名字的匿名对象）
Location2 g()
{
          Location2 A(1, 2);
          return A;
}

void objplay2()
{
          g();
}

void objplay3()
{
          //用匿名对象初始化m，此时C++编译器直接将匿名对象转成m;从匿名转成有名了
          Location2 m = g();
}

void objplay4()
{
          //用匿名对象初始化m，此时C++编译器直接将匿名对象转成m;从匿名转成有名了
          Location2 m2(1, 2);
          m2 = g();
}

void main601()
{
          //objplay2();
          //objplay3();
          //objplay4();

          cout << "hello..." << endl;
          system("pause");
          return;
}

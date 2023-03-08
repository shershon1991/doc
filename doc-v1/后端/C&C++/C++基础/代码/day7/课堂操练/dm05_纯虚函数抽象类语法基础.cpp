#include <iostream>
using namespace std;

//面向抽象类编程（面向一套预先定义好的接口编程）
//解耦合。。。模块的划分
class Figure //抽象类
{
public:
          //约定一个统一的接口，让子类必须去实现
          virtual void getArea() = 0; //纯虚函数
};

class Circle : public Figure
{
public:
          Circle(int a, int b)
          {
                    this->a = a;
                    this->b = b;
          }

          virtual void getArea()
          {
                    cout << "圆形的面积：" << 3.14 * a * a << endl;
          }

private:
          int a;
          int b;
};

class Tri : public Figure
{
public:
          Tri(int a, int b)
          {
                    this->a = a;
                    this->b = b;
          }

          virtual void getArea()
          {
                    cout << "三角形的面积：" << a * b / 2 << endl;
          }

private:
          int a;
          int b;
};

class Square : public Figure
{
public:
          Square(int a, int b)
          {
                    this->a = a;
                    this->b = b;
          }

          virtual void getArea()
          {
                    cout << "四边形的面积：" << a * b << endl;
          }

private:
          int a;
          int b;
};

void objplay5(Figure *base)
{
          base->getArea();
}

void main501()
{
          //Figer f; //err 抽象类不能被实例化
          Figure *base = NULL;

          Circle c1(10, 20);
          Tri t1(30, 40);
          Square s1(50, 60);

          objplay5(&c1);
          objplay5(&t1);
          objplay5(&s1);
          //c1.getArea();

          cout << "hello..." << endl;
          system("pause");
          return;
}

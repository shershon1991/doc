#include "iostream"
using namespace std;

//类的访问控制关键字
class MyClass
{
public:
protected:
private:
};

//封装有2层含义：
//1.对属性和方法进行封装
//2.对属性和方法进行访问控制
class MyCircle
{
public:
          double m_r;
          double m_s;

          double getR()
          {
                    return m_r;
          }
          void setR(double r)
          {
                    m_r = r;
          }
          double getS()
          {
                    m_s = 3.14 * m_r * m_r;
                    return m_s;
          }
};
//类的封装的威力
//类封装的成员变量和成员函数 //可以调用类的成员函数
void printCircle11(MyCircle *pC)
{
          cout << "c r:" << pC->getR() << endl;
          cout << "c s:" << pC->getS() << endl;
}
void printCircle12(MyCircle &myc)
{
          cout << "c s:" << myc.getS() << endl;
}
void printCircle13(MyCircle myc)
{
}
void main101()
{
          MyCircle c1, c2;
          c1.setR(10);
          cout << "c1的面积s:" << c1.getS() << endl;

          c1.setR(11);
          c2.setR(11);

          printCircle11(&c1);
          printCircle12(c2);

          cout << "hello..." << endl;
          system("pause");
          return;
}

class MyAdvCircle
{
private:
          double m_r;
          double m_s;

public:
          double getR()
          {
                    return m_r;
          }
          void setR(double r)
          {
                    m_r = r;
          }
          double getS()
          {
                    m_s = 3.14 * m_r * m_r;
                    return m_s;
          }
};
void main12()
{
          MyAdvCircle c1, c2;
          //c1.m_r = 10;//err
          c1.setR(10);

          cout << "hello..." << endl;
          system("pause");
          return;
}

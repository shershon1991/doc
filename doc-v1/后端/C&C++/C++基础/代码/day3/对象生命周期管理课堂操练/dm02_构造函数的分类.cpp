#include <iostream>
using namespace std;

class Test2
{
public:
          Test2()
          {
                    m_a = 0;
                    m_b = 0;
                    cout << "无参构造函数" << endl;
          }
          Test2(int a)
          {
                    m_a = a;
                    m_b = 0;
                    cout << "一参构造函数m_a:" << m_a << endl;
          }
          Test2(int a, int b)
          {
                    m_a = a;
                    m_b = b;
                    cout << "二参构造函数m_a:" << m_a << ", m_b:" << m_b << endl;
          }
          //赋值构造函数（copy构造函数）
          Test2(const Test2 &obj)
          {
                    cout << "我也是构造函数" << endl;
          }
          void printT()
          {
                    cout << "普通成员函数" << endl;
          }

private:
          int m_a;
          int m_b;
};

void main201()
{
          Test2 t1; //调用无参构造函数

          cout << "hello..." << endl;
          system("pause");
          return;
}

//调用有参构造函数的3种方法
void main202()
{
          //1括号法
          Test2 t1(1, 2);

          //2 =号法
          Test2 t2 = (3, 4); //C++对等号操作符进行了功能增强
          Test2 t3 = 5;

          //3直接调用构造函数
          Test2 t4 = Test2(1, 2); //匿名对象（匿名对象的去和留）抛砖

          cout << "hello..." << endl;
          system("pause");
          return;
}

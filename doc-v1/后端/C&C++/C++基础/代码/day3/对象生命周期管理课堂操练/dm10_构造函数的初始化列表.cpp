#include <iostream>
using namespace std;

class A
{
public:
          A(int _a)
          {
                    a = _a;
                    cout << "构造函数：" << a << endl;
          }
          ~A()
          {
                    cout << "析构函数：" << a << endl;
          }

private:
          int a;
};

//构造函数的初始化列表 解决：在B类中 组合了一个A类对象（A类设计了构造函数）
//根据构造函数的调用规则，设计A的构造函数，必须要用；没有机会初始化A
//新的语法
class B
{
public:
          B(int _b1, int _b2) : a1(1), a2(2)
          {
                    ;
          }
          B(int _b1, int _b2, int m, int n) : a1(m), a2(n)
          {
                    b1 = _b1;
                    b2 = _b2;
          }
          ~B()
          {
                    cout << "B的析构函数：" << endl;
          }

private:
          int b1;
          int b2;
          A a1;
          A a2;
};

//先执行 被组合对象的构造函数
//如果组合对象有多个，按照定义顺序，而不是按照初始化列表的顺序
//析构函数和构造函数的调用顺序相反
void objplay10()
{
          A a1(10);
          B objB(1, 2);
          //1.参数传递
          B objB2(1, 2, 3, 4);

          //2.调用顺序
          return;
}
void main1001()
{
          objplay10();

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;

class BB
{
public:
          void printC()
          {
                    cout << "c:" << c << endl;
          }
          void addC()
          {
                    c++;
          }
          static void getC()
          {
                    cout << "c:" << c << endl;
                    //在静态成员函数中，可以调用普通成员属性或者普通成员方法吗
                    //cout << "a:" << a << endl; //err
                    //静态函数中，不能使用普通成员属性和普通成员方法
          }

private:
          int a;
          int b;
          static int c;
};

int BB::c = 10;

void main1501()
{
          BB b1, b2, b3;
          b1.printC(); //10
          b2.addC();   //11
          b3.printC(); //11

          //静态成员函数的调用方法
          b3.getC();  //1.对象.
          BB::getC(); //类名::

          cout << "hello..." << endl;
          system("pause");
          return;
}

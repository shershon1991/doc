#include <iostream>
using namespace std;

class Test
{
public:
          Test(int a, int b) //===>Test(Test* this, int a, int b)
          {
                    this->a = a;
                    this->b = b;
          }
          void printT()
          {
                    cout << "a:" << a << endl;
                    cout << "b:" << this->b << endl;
          }
          //1、const写在什么位置，没有关系
          //2、const修饰的是谁?	修饰的是this指针所指向的内存空间
          void opVar(int a, int b) const //==>void opVar(const Test* this, int a, int b)
          {
                    a = 100;
                    //this->b = 100;	//err
                    cout << "a:" << a << endl;
                    cout << "b:" << this->b << endl;
          }

private:
          int a;
          int b;
};

void main1701()
{
          Test t1(1, 2);
          t1.printT(); //==>printT(&t1)

          cout << "hello..." << endl;
          system("pause");
          return;
}

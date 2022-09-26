#include <iostream>
using namespace std;

void main601()
{
          bool b1 = true; //告诉C++编译器给我分配1个字节的内存

          cout << "sizeof(bool):" << sizeof(b1) << endl;

          //bool变量为1或0
          b1 = 10;
          cout << "b1:" << b1 << endl;

          b1 = -10;
          cout << "b1:" << b1 << endl;

          b1 = 0;
          cout << "b1:" << b1 << endl;

          cout << "hello..." << endl;
          system("pause");
          return;
}

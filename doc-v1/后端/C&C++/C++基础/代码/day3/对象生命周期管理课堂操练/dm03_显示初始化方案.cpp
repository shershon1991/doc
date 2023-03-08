#include <iostream>
using namespace std;

class Test3
{
public:
          void init(int _a, int _b)
          {
                    a = _a;
                    b = _b;
          }

private:
          int a;
          int b;
};

void main301()
{
          //类没有提供构造函数，C++编译器会自动给你提供一个默认的构造函数
          //类没有提供copy构造函数 C++编译器会自动给程序员提供一个默认的copy构造函数
          Test3 t1;
          int a = 10;
          int b = 20;
          t1.init(a, b);

          Test3 tArray[3];
          tArray[0].init(1, 2);
          tArray[1].init(1, 2);
          tArray[2].init(1, 2);

          cout << "hello..." << endl;
          system("pause");
          return;
}

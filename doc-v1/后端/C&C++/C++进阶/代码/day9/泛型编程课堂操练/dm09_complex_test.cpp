#include <iostream>
using namespace std;
#include "dm09_complex.hpp"

void main901()
{
          Complex9<int> c1(1, 2);
          Complex9<int> c2(3, 4);

          Complex9<int> c3 = c1 + c2;

          cout << c3 << endl;

          //滥用友元函数
          {
                    //Complex9<int> c4 = MySub(c1, c2);
                    //cout << c4 << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

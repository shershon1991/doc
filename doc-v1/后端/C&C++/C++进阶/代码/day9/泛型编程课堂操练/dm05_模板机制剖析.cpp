#include <iostream>
using namespace std;

//1.cpp
//gcc -S 1.cpp -o 1.s
template <typename T>
void myswap5(T &a, T &b)
{
          T c;
          c = a;
          a = b;
          b = c;

          cout << "我是模板函数，欢迎调用我" << endl;
}

int main501()
{
          {
                    int x = 10;
                    int y = 20;

                    myswap5(x, y);
                    printf("x:%d, y:%d \n", x, y);
          }

          {
                    char a = 'a';
                    char b = 'b';

                    myswap5(a, b);
                    printf("a:%c, b:%c \n", a, b);
          }

          cout << "hello..." << endl;
          system("pause");
          return 0;
}
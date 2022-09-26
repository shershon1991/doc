#include <iostream>
using namespace std;

class Parent21
{
public:
          Parent21(int a = 0)
          {
                    this->a = a;
          }

          void print()
          {
                    cout << "我是爹..." << endl;
          }

private:
          int a;
};

class Parent22
{
public:
          Parent22(int a = 0)
          {
                    this->a = a;
          }

          virtual void print()
          {
                    cout << "我是爹..." << endl;
          }

private:
          int a;
};

void main201()
{
          printf("sizeof(Parent21):%d sizeof(Parent22):%d \n", sizeof(Parent21), sizeof(Parent22));

          cout << "hello..." << endl;
          system("pause");
          return;
}

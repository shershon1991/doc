#include <iostream>
using namespace std;

class Parent5
{
public:
          Parent5(int a, int b)
          {
                    this->a = a;
                    this->b = b;
                    cout << "父类构造函数..." << endl;
          }
          ~Parent5()
          {
                    cout << "父类析构函数..." << endl;
          }
          void printP(int a, int b)
          {
                    this->a = a;
                    this->b = b;
                    cout << "我是爹..." << endl;
          }

private:
          int a;
          int b;
};

class Child5 : public Parent5
{
public:
          Child5(int a, int b, int c) : Parent5(a, b)
          {
                    this->c = c;
                    cout << "子类构造函数..." << endl;
          }
          ~Child5()
          {
                    cout << "子类析构函数..." << endl;
          }
          void printC()
          {
                    cout << "我是儿子..." << endl;
          }

private:
          int c;
};

void playobj()
{
          Child5 c1(1, 2, 3);
}

void main501()
{
          //Parent5 p(1, 2);
          playobj();

          cout << "hello..." << endl;
          system("pause");
          return;
}
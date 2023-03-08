#include <iostream>
using namespace std;

//结论：多态使用父类指针指向子类对象 和 父类步长++，是两个不同的概念
class Parent4
{
public:
          Parent4(int a = 0)
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

class Child4 : public Parent4
{
public:
          Child4(int a = 0, int b = 0) : Parent4(a)
          {
                    //this->b = b;
          }

          virtual void print()
          {
                    cout << "我是儿..." << endl;
          }

private:
          int b;
};

void howToPrint4(Parent4 *base)
{
          base->print();
}

void main401()
{
          Child4 c1;
          Parent4 *pP = NULL;
          Child4 *pC = NULL;

          Child4 array[] = {Child4(1), Child4(2), Child4(3)};
          pP = array;
          pC = array;

          pP->print();
          pC->print();

          pP++;
          pC++;

          pP->print();
          pC->print();

          cout << "hello..." << endl;
          system("pause");
          return;
}

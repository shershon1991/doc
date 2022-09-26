#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//虚析构函数
class A14
{
public:
          A14()
          {
                    p = new char[20];
                    strcpy(p, "obja");
                    printf("A14()\n");
          }
          virtual ~A14()
          {
                    delete[] p;
                    printf("~A14()\n");
          }

private:
          char *p;
};

class B14 : public A14
{
public:
          B14()
          {
                    p = new char[20];
                    strcpy(p, "objb");
                    printf("B14()\n");
          }
          ~B14()
          {
                    delete[] p;
                    printf("~B14()\n");
          }

private:
          char *p;
};

class C14 : public B14
{
public:
          C14()
          {
                    p = new char[20];
                    strcpy(p, "objc");
                    printf("C14()\n");
          }
          ~C14()
          {
                    delete[] p;
                    printf("~C14()\n");
          }

private:
          char *p;
};

//只是执行了父类的析构函数
//想通过父类指针把多个子类对象的析构函数都执行一遍
//想通过父类指针释放所有的资源
void howToDelete(A14 *base)
{
          delete base; //这句话不会表现出多态那种属性
}

void main1401()
{
          C14 *myC = new C14;
          //howToDelete(myC);

          delete myC; //直接通过子类对象释放资源，不需要写virtual

          cout << "hello..." << endl;
          system("pause");
          return;
}

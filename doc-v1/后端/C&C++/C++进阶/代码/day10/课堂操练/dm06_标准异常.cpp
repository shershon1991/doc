#include <iostream>
using namespace std;
#include "string"

class Teacher
{
public:
          Teacher(int age)
          {
                    if (age > 100)
                    {
                              string s = "年龄太大";
                              throw out_of_range(s);
                    }
                    this->age = age;
          }

private:
          int age;
};

void main601()
{
          try
          {
                    Teacher t1(150);
          }
          catch (out_of_range e)
          {
                    cout << e.what() << endl;
          }
          catch (...)
          {
                    cout << "未知类型异常" << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

class MyException6 : public exception
{
public:
          MyException6(const char *p) : exception(p)
          {
                    this->p = p;
          }
          virtual const char *what()
          {
                    return p;
          }

private:
          const char *p;
};

void main602()
{
          try
          {
                    throw MyException6("测试从基类继承的异常");
          }
          catch (exception &e)
          {
                    cout << e.what() << endl;
          }
          catch (...)
          {
                    cout << "未知类型异常" << endl;
          }

          system("pause");
          return;
}
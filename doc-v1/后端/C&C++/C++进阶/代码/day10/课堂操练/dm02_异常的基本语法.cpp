#include <iostream>
using namespace std;

//1.基本语法
//2.发生异常后，是跨函数的
//3.接收异常后可以不处理，再抛出
//4.catch异常时 严格按照类型进行catch
void main203()
{
          try
          {
                    throw 'Z';
          }
          catch (int e)
          {
                    cout << "捕获int类型异常" << endl;
          }
          catch (...)
          {
                    cout << "捕获未知类型异常" << endl;
          }

          system("pause");
          return;
}

void divide(int x, int y)
{
          if (y == 0)
          {
                    throw x; //抛出int类型异常
          }
          cout << "divide结果：" << x / y << endl;
}

void myDivide(int x, int y)
{
          divide(x, y);
}

void main202()
{
          myDivide(10, 0);

          cout << "hello..." << endl;
          system("pause");
          return;
}

void main201()
{
          try
          {
                    //divide(10, 2);
                    //divide(10, 0);
                    myDivide(10, 0);
          }
          catch (int e)
          {
                    cout << e << "被0除" << endl;
          }
          catch (...) //
          {
                    cout << "其他未知异常" << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

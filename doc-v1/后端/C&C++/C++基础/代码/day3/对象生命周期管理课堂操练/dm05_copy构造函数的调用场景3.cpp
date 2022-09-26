#include <iostream>
using namespace std;

class Location
{
public:
          Location(int xx = 0, int yy = 0)
          {
                    X = xx;
                    Y = yy;
                    cout << "Constructor Object.\n";
          }
          Location(const Location &obj) //copy构造函数
          {
                    X = obj.X;
                    Y = obj.Y;
                    cout << "调用copy构造函数 \n";
          }
          ~Location()
          {
                    cout << X << "," << Y << " Object destroyed." << endl;
          }
          int GetX()
          {
                    return X;
          }
          int GetY()
          {
                    return Y;
          }

private:
          int X, Y;
};

void f(Location p)
{
          cout << p.GetX() << endl;
}

void playobj()
{
          Location a(1, 2);
          Location b = a;
          cout << "b对象已经初始化完毕" << endl;

          f(b); //b实参去初始化形参p，会调用copy构造函数
}

void main501()
{
          playobj();

          cout << "hello..." << endl;
          system("pause");
          return;
}

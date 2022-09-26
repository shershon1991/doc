#include <iostream>
using namespace std;

class MyPoint; //类的前置声明
class MyPoint
{
public:
          void setPoint(int _x1, int _y1)
          {
                    x1 = _x1;
                    y1 = _y1;
          }
          int getX1()
          {
                    return x1;
          }
          int getY1()
          {
                    return y1;
          }

private:
          int x1;
          int y1;
};

class AdvCircle
{
public:
          void setCircle(int _r, int _x0, int _y0)
          {
                    r = _r;
                    x0 = _x0;
                    y0 = _y0;
          }

public:
          int judge(MyPoint &myp)
          {
                    int dd = (myp.getX1() - x0) * (myp.getX1() - x0) + (myp.getY1() - y0) * (myp.getY1() - y0);
                    if (dd <= r * r)
                    {
                              return 1;
                    }
                    else
                    {
                              return 0;
                    }
          }

private:
          int r;
          int x0;
          int y0;
};

void main201()
{
          AdvCircle c1;
          MyPoint p1;

          c1.setCircle(2, 3, 3);
          p1.setPoint(4, 4);

          //在圆内为1，不在圆内为0
          int tag = c1.judge(p1);
          if (tag == 1)
          {
                    cout << "点在圆内" << endl;
          }
          else
          {
                    cout << "点不在圆内" << endl;
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

#include <iostream>
using namespace std;

#include "AdvCircle.h"
#include "MyPoint.h"

void main()
{
          AdvCircle c1;
          MyPoint p1;

          c1.setCircle(2, 3, 3);
          p1.setPoint(7, 7);

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

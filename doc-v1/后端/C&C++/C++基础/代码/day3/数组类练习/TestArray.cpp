#include <iostream>
using namespace std;
#include "MyArray.h"

//类的框架设计完毕
//类的测试案例

//重载 []
//void operator[](int i);
//int operator[](int i);
//int& operator[](int i);
void main()
{
          Array a1(10);

          for (int i = 0; i < a1.length(); i++)
          {
                    //a1.setData(i, i);
                    a1[i] = i;
          }

          cout << "\n打印数组a1：";
          for (int i = 0; i < a1.length(); i++)
          {
                    //cout << a1.getData(i) << " ";
                    cout << a1[i] << " ";
          }
          cout << endl;

          Array a2 = a1;
          cout << "打印数组a2：";
          for (int i = 0; i < a2.length(); i++)
          {
                    cout << a2[i] << " ";
          }
          cout << endl;

          Array a3(5);
          Array a4(5);
          {
                    //a3 = a1;
                    a4 = a3 = a1;
                    cout << "打印数组a3：";
                    for (int i = 0; i < a3.length(); i++)
                    {
                              cout << a3[i] << " ";
                    }
                    cout << endl;
          }

          if (a1 == a3)
          {
                    printf("相等 \n");
          }
          else
          {
                    printf("不相等 \n");
          }
          //a3.operator==(a1)
          //bool operator==(Array &a1);

          if (a1 != a3)
          {
                    printf("不相等 \n");
          }
          else
          {
                    printf("相等 \n");
          }
          //a3.operator!=(a1)
          //bool operator!=(Array &a1)

          cout << "hello..." << endl;
          system("pause");
          return;
}

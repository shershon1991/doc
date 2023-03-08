#include <iostream>
using namespace std;

struct Teacher
{
          char name[64];
          int age;
};
int getTeacher121(Teacher **p)
{
          Teacher *tmp = NULL;

          if (p == NULL)
          {
                    return -1;
          }
          tmp = (Teacher *)malloc(sizeof(Teacher));
          if (tmp == NULL)
          {
                    return -2;
          }
          tmp->age = 33;
          *p = tmp;
}
int getTeacher122(Teacher *&myp)
{
          //给myp赋值相当于给main函数中的pT1赋值
          myp = (Teacher *)malloc(sizeof(Teacher));
          if (myp == NULL)
          {
                    return -1;
          }
          myp->age = 36;
}
void FreeTeacher(Teacher *pT)
{
          if (pT == NULL)
          {
                    return;
          }
          free(pT);
}
void main1201()
{
          Teacher *pT1 = NULL;

          //1.C语言中的二级指针
          getTeacher121(&pT1);
          cout << "age:" << pT1->age << endl;
          FreeTeacher(pT1);

          //2.C++中的引用（指针的引用）
          getTeacher122(pT1);
          cout << "age:" << pT1->age << endl;
          FreeTeacher(pT1);

          cout << "hello..." << endl;
          system("pause");
          return;
}

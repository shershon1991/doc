#include <iostream>
using namespace std;
//#include "SeqList.h"
#include "SeqList.cpp"

struct Teacher
{
          char name[60];
          int age;
};

void main_seqlist_play()
{
          Teacher t1, t2, t3, tmp;
          t1.age = 31;
          t2.age = 32;
          t3.age = 33;

          SeqList<Teacher> list(10);
          list.insert(t1, 0);
          list.insert(t2, 0);
          list.insert(t3, 0);

          //测试链表的遍历
          for (int i = 0; i < list.getLen(); i++)
          {
                    list.get(i, tmp);
                    cout << tmp.age << " ";
          }

          //测试链表的销毁
          while (list.getLen() > 0)
          {
                    list.del(0, tmp);
                    cout << tmp.age << " ";
          }

          return;
}

void main101()
{
          main_seqlist_play();

          cout << "hello..." << endl;
          system("pause");
          return;
}
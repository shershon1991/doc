#include <iostream>
using namespace std;

void main1301()
{
          //普通引用
          int a = 10;
          int &b = a;
          printf("b:%d \n", b);

          //常引用
          int x = 20;
          const int &y = x; //让变量拥有只读属性，不能通过y去修改x
          //y = 21;

          //常引用初始化分为2种情况
          //1.变量初始化常引用
          {
                    int x1 = 30;
                    const int &y1 = x1;
          }
          //2.用字面量初始化常引用
          {
                    const int a = 41; //C++编译器将a放入符号表中了
                    //int& m = 42;//普通引用一个字面量，请问字面量有没有内存地址？没有
                    //引用就是给内存取多个别名（门牌号）

                    const int &m = 43; //C++编译器会分配内存空间
          }

          cout << "hello..." << endl;
          system("pause");
          return;
}

struct Teacher
{
          char name[64];
          int age;
};
void printTeacher(const Teacher &myt)
{
          //常引用让实参变量拥有只读的属性
          //myt.age = 38;
          printf("myt.age:%d \n", myt.age);
}
void main1302()
{
          Teacher t1;

          t1.age = 36;
          printTeacher(t1);

          system("pause");
}
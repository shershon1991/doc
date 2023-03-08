#include <iostream>
using namespace std;

//1.单独定义引用时，必须初始化，说明很像一个常量
void main1001()
{
          const int c1 = 10;

          int a = 10;
          int &b = a; //b很像一个常量

          printf("&a:%d \n", &a);
          printf("&b:%d \n", &b); //a和b是同一块内存空间的门牌号

          cout << "hello..." << endl;
          system("pause");
          return;
}

//2.普通引用有自己的空间吗？有
struct Teacher
{
          char name[64];
          int age;

          int &a;
          int &b; //很像指针所占的内存空间大小
};
void modifyA101(int &a1)
{
          a1 = 20;
}
void modifyA102(int *const a1)
{
          *a1 = 20;
}
//3.引用的本质
void main1002()
{
          int a = 10;
          modifyA101(a); //指向这个函数调用的时候，不需要取a的地址
          cout << "a:" << a << endl;

          a = 10;
          modifyA102(&a); //如果是指针，需要我们手工的取实参地址
          cout << "a:" << a << endl;

          printf("sizeof(Teacher):%d \n", sizeof(Teacher));

          cout << "hello..." << endl;
          system("pause");
          return;
}

//4.间接赋值
void main1003()
{
}
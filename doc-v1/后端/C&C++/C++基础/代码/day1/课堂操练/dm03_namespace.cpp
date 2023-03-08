#include "iostream";
using namespace std;

//1.文件中iostream 没有引入标准的std 需要我们手工写
//2.如果不写using namespace std; 需要显示地引入std
void main301()
{
          //std::cout << "namespace test" << std::endl;
          cout << "namespace test" << endl;

          system("pause");
}

//3.定义命名空间
namespace namespaceA
{
          int a = 10;
}

namespace namespaceB
{
          int a = 20;
          namespace namespaceC
          {
                    struct Teacher
                    {
                              char name[32];
                              int age;
                    };
          }
}

//4.使用命名空间
void main302()
{
          using namespace namespaceA;
          using namespace namespaceB;
          cout << namespaceA::a << endl;
          cout << namespaceB::a << endl;

          //显式地，写全
          {
                    namespaceB::namespaceC::Teacher t1;
                    t1.age = 33;
          }

          {
                    using namespaceB::namespaceC::Teacher;
                    Teacher t2;
                    t2.age = 32;
          }

          system("pause");
}

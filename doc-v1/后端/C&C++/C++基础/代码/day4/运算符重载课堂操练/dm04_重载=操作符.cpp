#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Name
{
public:
          Name(const char *myp)
          {
                    len = strlen(myp);
                    p = (char *)malloc(len + 1);
                    strcpy(p, myp);
          }
          //解决方案：手工地编写copy构造函数，使用深拷贝
          Name(const Name &obj1)
          {
                    len = obj1.len;
                    p = (char *)malloc(len + 1);
                    strcpy(p, obj1.p);
          }

          //obj3 = obj1;	//=号操作
          //obj3.operator=(obj1)
          Name &operator=(Name &obj1)
          {
                    //先释放旧的内存
                    if (this->p != NULL)
                    {
                              delete[] p;
                              len = 0;
                    }
                    //根据obj1分配内存
                    this->len = obj1.len;
                    this->p = new char[len + 1];
                    //把obj1赋值给obj3
                    strcpy(this->p, obj1.p);
                    return *this;
          }

          ~Name()
          {
                    if (p != NULL)
                    {
                              free(p);
                              p = NULL;
                              len = 0;
                    }
          }

private:
          char *p;
          int len;
};

void objectmain()
{
          Name obj1("abcdefg");
          Name obj2 = obj1; //默认的copy构造函数，C++编译器给我们提供
          Name obj3("obj3");

          obj3 = obj1; //=号操作
          //obj3.operator=(obj1)

          obj1 = obj2 = obj3;
          //obj2.operator(obj3);
          //obj1 = void
}

void main401()
{
          objectmain();

          cout << "hello..." << endl;
          system("pause");
          return;
}

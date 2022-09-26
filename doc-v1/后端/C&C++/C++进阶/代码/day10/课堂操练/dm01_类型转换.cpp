#include <iostream>
using namespace std;

void printBuf(const char *p)
{
          //p[0] = 'Z';//err
          char *p1 = NULL;
          p1 = const_cast<char *>(p); //const char* ===> char* 去掉只读属性
          p1[0] = 'Z';                //通过p1修改了内存空间
          cout << p << endl;
}

void main103()
{
          char buf[] = "abcdefg";
          //程序员要确保p指向的内存空间可以被修改，若不能修改会带来灾难性后果
          printBuf(buf);

          system("pause");
}

class Animal
{
public:
          virtual void cry() = 0;
};

class Dog : public Animal
{
public:
          virtual void cry()
          {
                    cout << "汪汪" << endl;
          }
          void doHome()
          {
                    cout << "看家" << endl;
          }
};

class Cat : public Animal
{
public:
          virtual void cry()
          {
                    cout << "喵喵" << endl;
          }
          void doThing()
          {
                    cout << "抓老鼠" << endl;
          }
};

void playObj(Animal *base)
{
          // 1.有继承 2.有虚函数重写 3.父类指针（引用）指向子类对象 == > 多态成立的三个条件
          //可以识别子类对象
          base->cry();

          //dynamic_cast运行时类型识别
          //父类对象===>子类对象 向下转型
          //把老子转成小子
          Dog *pDog = dynamic_cast<Dog *>(base);
          if (pDog != NULL)
          {
                    pDog->doHome();
          }
          Cat *pCat = dynamic_cast<Cat *>(base);
          if (pCat != NULL)
          {
                    pCat->doThing();
          }
}

void main102()
{
          Dog d1;
          Cat c1;

          playObj(&d1);
          playObj(&c1);

          system("pause");
          return;
}

void main101()
{
          double dpi = 3.1415926;

          int num1 = (int)dpi;              //C类型转换
          int num2 = static_cast<int>(dpi); //静态类型转换 编译时C++编译器会做类型检查
          int num3 = dpi;                   //C语言中 隐式类型转换的地方 均可使用static_cast<>()进行类型转换

          //char * ==> int *
          char *p1 = (char *)"abcdefg...";
          int *p2 = NULL;
          //p2 = static_cast<int *>(p1);//err
          p2 = reinterpret_cast<int *>(p1);

          cout << "p1:" << p1 << endl;
          cout << "p2:" << p2 << endl;

          //总结：通过reinterpret_cast和static_cast把C语言的强制类型转换都覆盖了

          cout << "hello..." << endl;
          system("pause");
          return;
}

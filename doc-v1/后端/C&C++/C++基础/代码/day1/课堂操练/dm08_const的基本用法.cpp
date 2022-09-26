#include <iostream>
using namespace std;

struct Teacher
{
          char name[64];
          int age;
};

//指针所指向的内存空间不能被修改
int operatorTeacher01(const Teacher *pT)
{
          //pT->age = 28;
          return 0;
}

//指针变量本身不能被修改
int operatorTeacher02(Teacher *const pT)
{
          pT->age = 28;
          //pT = NULL;
          return 0;
}

int operatorTeacher03(const Teacher *const pT)
{
          //pT->age = 28;
          //pT = NULL;

          printf("age:%d\n", pT->age);
          return 0;
}

void main801()
{
          /*const int a;
	int const b;

	const int* c;//const修饰的是指针所指向的内存空间 不能被修改
	int* const d;
	const int* const e;*/

          Teacher t1;
          t1.age = 33;
          operatorTeacher03(&t1);

          cout << "hello..." << endl;
          system("pause");
          return;
}

//1.
//C语言中的const是一个冒牌货
//C++中的const是一个真正的常量
//2.
void main802()
{
          //好像a是一个常量
          const int a = 10;
          //a = 11;

          int *p = NULL;
          p = (int *)&a;
          *p = 20;

          printf("a:%d \n", a);
          printf("*p:%d \n", *p);
          system("pause");
}

//4.const 和 #define的相同之处
//Const常量是由编译器处理的，提供类型检查和作用域检查
//#define,在预处理器阶段处理，就是简单的文本替换
#define d 20
void main804()
{
          //int a = 10;
          //int b = 20;
          //int array[a + b];//linux内核里是成立的，因为编译Linux内核的gcc编译器支持
          //C、C++编译器不支持

          const int c = 10;
          //const int d = 20;
          int array2[c + d];

          system("pause");
}

//5.Const常量是由编译器处理的，提供类型检查和作用域检查
void fun1()
{
#define a 10
          const int b = 20;
          //#undef a
}
void fun2()
{
          printf("a:%d\n", a);
          //printf("b:%d\n", b);
}
int main805()
{
          fun1();
          fun2();

          system("pause");
          return 0;
}
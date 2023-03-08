#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//定义一个结构体类型

//定义了一个数据类型（固定大小内存块的别名），还没有分配内存
//类型的重定义

struct Teacher1
{
          char name[64];
          int age;
          int id;
};

typedef struct Teacher2
{
          char name[64];
          int age;
          int id;
} Teacher2;

//用类型定义变量的3种方法
struct Student
{
          char name[64];
          int age;
} s1, s2; //定义类型的同时，定义变量

struct
{
          char name[64];
          int age;
} s3, s4; //匿名类型 定义变量

//初始化变量的3种方法
struct Student2
{ //初始化变量：2
          char name[64];
          int age;
} s5 = {"Shershon", 28};

struct Student3
{ //初始化变量：3
          char name[64];
          int age;
} s6 = {"Shershon", 28};

void main11()
{
          //struct Teacher1 t1;//告诉编译器给我分配内存
          Teacher2 t1;                    //告诉C编译器给我分配内存
          Teacher2 t2 = {"aaaa", 32, 02}; //初始化变量：1

          t1.age = 31; //.操作符是干什么的，有没有操作内存
                       //是寻址操作符，计算age相对于t1大变量的偏移量 ===》 在CPU中进行计算，没有操作内存

          //通过指针的方法操作内存空间
          {
                    Teacher2 *p = NULL;
                    p = &t2;
                    printf("p->age:%d \n", p->age); //->操作符是干什么的，有没有操作内存
                        //是寻址操作符，计算age相对于t2大变量的偏移量 ===》 在CPU中进行计算，没有操作内存
                    printf("p->name:%s \n", p->name);
                    printf("p->id:%d \n", p->id);
          }

          strcpy(t1.name, "t1name");
          printf("t1.name:%s \n", t1.name);

          system("pause");
          return;
}

void copyTeacher11(Teacher2 to, Teacher2 from)
{
          to = from;
}

void copyTeacher12(Teacher2 *to, Teacher2 *from)
{
          *to = *from;
}

void main12()
{
          Teacher2 t1 = {"Shershon", 28, 01};
          Teacher2 t2;
          Teacher2 t3;
          memset(&t3, 0, sizeof(t3));

          t2 = t1;

          //编译器给我们提供简单=赋值操作，我们要顺从
          printf("t2.name:%s \n", t2.name);
          printf("t2.age:%d \n", t2.age);

          /*copyTeacher11(t3, t1);
	printf("after copyTeacher11() \n");
	printf("t3.name:%s \n", t3.name);
	printf("t3.age:%d \n", t3.age);*/

          copyTeacher12(&t3, &t1);
          printf("after copyTeacher12() \n");
          printf("t3.name:%s \n", t3.name);
          printf("t3.age:%d \n", t3.age);

          system("pause");
          return;
}
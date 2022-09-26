#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Student
{
          char name[64];
          int id;
} Student;

typedef struct Teacher
{
          char name[64];
          int id;
          char *p;
          char **p2;
          Student s1;
          Student *p3;
} Teacher;

/*typedef struct AdvTeacher
{
	char name[64];
	int id;
	struct AdvTeacher AdvTeacher;
}AdvTeacher;*/

typedef struct AdvTeacher2
{
          char name[64];
          int id;
          struct AdvTeacher2 *p;
} AdvTeacher;

//1.结构体中套结构体
//2.结构体中套一个结构体的指针
//3.结构体中套一个自己类型的结构体元素--error
//4.结构体中套一个指向自己类型的结构体的指针

//数据类型本质：固定大小内存块的别名

//函数的嵌套调用 和 结构体数据类型的定义 是两个不同的概念
void main11()
{
          Teacher t1;
          AdvTeacher advT1;

          system("pause");
          return;
}

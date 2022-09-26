#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main31()
{
          int a;
          int b[10];

          printf("b:%d, b+1:%d, &b:%d, &b+1:%d\n", b, b + 1, &b, &b + 1);
          //b+1 &b+1 结果不一样
          //b代表的是数组首元素的地址
          //&b代表的是整个数组的地址

          printf("sizeof(a):%d\n", sizeof(a));
          printf("sizeof(b):%d\n", sizeof(b));

          printf("hello ...\n");
          system("pause");
}

/*struct Teacher
{
	char name[64];
	int age;
};*/

typedef struct Teacher2
{
          char name[64];
          int age;
} Teacher2;

void main32()
{
          int a;
          int b[10];

          //struct Teacher t1;
          //t1.age = 31;

          Teacher2 t2;
          t2.age = 31;

          printf("hello ...\n");
          system("pause");
}
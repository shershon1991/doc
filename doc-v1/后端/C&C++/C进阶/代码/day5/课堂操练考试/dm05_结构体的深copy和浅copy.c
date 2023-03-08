#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher
{
          char name[64];
          int age;
          char *pname2;
} Teacher;

//编译器的=操作，只会把指针变量的值，从from拷贝到to
//但是不会把指针变量所指向的内存空间拷贝，即浅拷贝

//结构体中嵌套一个1级指针或2级指针

//如果想执行深拷贝，需要再显式地分配内存
void copyTeacher(Teacher *to, Teacher *from)
{
          //*to = *from;
          //memcpy(to, from, sizeof(Teacher));

          to->pname2 = (char *)malloc(100); //显式地分配内存
          strcpy(to->pname2, from->pname2);
}

void main51()
{
          Teacher t1;
          Teacher t2;

          strcpy(t1.name, "name1");
          t1.pname2 = (char *)malloc(100);
          strcpy(t1.pname2, "name2");

          //t1 copy至 t2
          copyTeacher(&t2, &t1);

          if (t1.pname2 != NULL)
          {
                    free(t1.pname2);
                    t1.pname2 = NULL;
          }

          if (t2.pname2 != NULL)
          {
                    free(t2.pname2);
                    t2.pname2 = NULL;
          }

          system("pause");
          return;
}

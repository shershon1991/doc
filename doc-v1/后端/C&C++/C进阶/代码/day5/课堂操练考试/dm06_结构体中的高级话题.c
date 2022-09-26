#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct AdvTeacher
{
          char name[64];
          int age;
          int p;
          char *pname2;
} AdvTeacher;

void main61()
{
          AdvTeacher t1;
          AdvTeacher *p = NULL;

          p - 1; //编译通过，运行通过==》这行代码，在CPU中计算
          p - p;

          {
                    int offsize = (int)&(p->age);
                    printf("%d \n", offsize);
          }

          system("pause");
          return;
}

//1.一旦结构体定义下来，则结构体中的成员的内存布局就定下来了
//2.可以通过age地址，去求大的结构体的内存地址
void main62()
{
          AdvTeacher t1;
          AdvTeacher *p = NULL;
          p = &t1;
          //p - 1;//编译通过，运行通过==》这行代码，在CPU中计算
          //p - p;

          {
                    int offsize1 = (int)&(p->age);
                    int offsize2 = (int)&(((AdvTeacher *)0)->age);
                    printf("offsize1:%d \n", offsize1);
                    printf("offsize2:%d \n", offsize2);
          }

          system("pause");
          return;
}
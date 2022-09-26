#include <stdio.h>

int main1()
{
          int *a[10]; //定义了一个指针数组，一共10个成员，每个成员都是int *类型
          printf("%d, %d\n", sizeof(a), sizeof(a[0]));

          short *b[10]; //定义了一个指针数组，一共10个成员，每个成员都是int *类型
          printf("%d, %d\n", sizeof(b), sizeof(b[0]));

          system("pause");
          return 0;
}

int main2()
{
          int a = 100;
          int *p = &a;
          int **pp = &p; //定义了一个二级指针，指向了一个一级指针的地址
          **pp = 10;     //通过二级指针修改内存的值
          printf("%d\n", a);

          system("pause");
          return 0;
}
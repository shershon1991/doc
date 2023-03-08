#include <stdio.h>

int main1()
{
          int a = 0x1234;
          int *p = &a;
          p += 1;
          printf("%x\n", *p);

          system("pause");
          return 0;
}

int main2()
{
          int a = 100;
          const int *p = &a;
          //*p = 10;//不能将const int *作为左值使用
          int *p1 = p; //这是C语言不严谨的地方
          *p1 = 10;
          printf("%d\n", a);

          system("pause");
          return 0;
}

int main3()
{
          int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          int *p = buf;
          //buf++;//buf = buf + 1;buf是数组，是一个常量，常量不能做左值

          //printf("%d\n", *p);
          printf("%d, %d\n", sizeof(p), sizeof(buf));

          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", p[i]); //C语言允许指针通过下标的方式访问数组的元素
          }

          system("pause");
          return 0;
}
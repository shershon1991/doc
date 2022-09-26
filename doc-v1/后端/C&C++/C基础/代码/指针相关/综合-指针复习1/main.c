#include <stdio.h>

int main1()
{
          int array[100] = {1, 2, 3, 4, 5};
          int *p = array;
          //*p = 100;将100赋值给p指向的内存
          //p = 100;将100赋值给变量p
          printf("%u\n", p);
          p++; //移动了一个int内存大小
          printf("%u\n", p);
          int i = 30;
          p = &i;
          *p = 300;
          printf("i = %d\n", i);
          printf("hello world\n");
          return 0;
}

int main2()
{
          int *p;
          //*p = 100;//给野指针内存赋值错误的，
          return 0;
}

int main3()
{
          int i = 0x12345678;
          char *p = &i;
          printf("%x,%x,%x,%x\n", p[0], p[1], p[2], p[3]);

          const int *p1 = &i;
          //*p1 = 100;
          printf("%x\n", *p1);

          int *const p2 = &i;
          *p2 = 100;

          int i1 = 0;
          //p2 = &i1;p2只能指向初始化时指向的变量地址，不能修改

          printf("i = %d\n", i);
          return 0;
}

int main4()
{
          int array[100] = {0};
          int *p = array;

          p += 5;
          p -= 2;
          p[3] = 20; //使用指针访问数组成员，从语法上和数组一样，通过[]和下标方式

          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("array[%d] = %d\n", i, array[i]);
          }

          printf("---------\n");

          int *p1 = &array[2];
          int *p2 = &array[5];

          p1 += 2;
          p2 -= 1;
          if (p1 == p2)
          {
                    printf("p1 == p2\n");
          }
          else
          {
                    printf("p1 <> p2\n");
          }
          printf("%d\n", p2 - p1);
          return 0;
}

int main()
{
          int *s[10] = {0}; //定义一个数组
          int(*p)[10] = 0;  //定义一个指针变量，指向int [10]这么大的一种数据类型

          int array[3][4] = {0};
          int(*p1)[4] = array;

          return 0;
}
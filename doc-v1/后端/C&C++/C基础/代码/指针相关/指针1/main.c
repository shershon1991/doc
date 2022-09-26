#include <stdio.h>

int main1()
{
          int a = 0;
          int b = 10;
          char buf[10];
          printf("%p,%p,%p\n", &a, &b, buf);

          int *p;
          p = &a;            //得到变量a的地址，赋值给变量p
          printf("%X\n", p); //地址虽然是一个整数，但其是一个特殊的整数，只能直接当成整数来操作

          int *p1; //定义一个变量，名字叫做p1,它可以指向一个int型变量的地址
          p1 = &b; //指针变量的值是通过获取变量地址的方式赋值的
          printf("%X\n", p1);

          char *p2;
          p2 = buf;
          printf("%X\n", p2);

          system("pause");
          return 0;
}

int main2()
{
          int a = 3;
          int *p;
          p = &a;
          int b = *p;
          printf("%d\n", b);

          *p = 10; //通过指针修改所指向的变量的值
          printf("a = %d\n", a);

          printf("--------------------------\n");

          char buf[10];
          printf("%u, %u, %u, %u\n", buf, &buf[0], &buf[1], &buf[2]);

          int buf1[10];
          printf("%u, %u, %u, %u\n", buf1, &buf1[0], &buf1[1], &buf1[2]);

          char c = 0;
          char *p2 = &c;
          printf("%X\n", p2);

          void *p3;        //这个叫无类型指针，代表这只是一个指针变量，不指向任何具体的数据类型
          void *p4 = NULL; //将指针赋值NULL，值为NULL的指针，我们称为空指针

          printf("%d\n", sizeof(p3));
          printf("%d\n", sizeof(p4));

          system("pause");
          return 0;
}

int main3()
{
          int a = 1;
          int b = 2;
          int c = 3;
          int *p;

          p = &a;
          *p = 10;

          p = &b;
          *p = 20;

          p = &c;
          *p = 30;

          printf("a = %d, b = %d, c = %d\n", a, b, c);

          system("pause");
          return 0;
}

int main4() //指针的兼容性
{
          float a = 3.14;
          int i = a; //自动数据类型转化，将浮点数的小数部分舍弃

          int *p = &a; //严重的错误，因为指针类型不兼容
          printf("%d\n", *p);

          system("pause");
          return 0;
}

int main5() //指向常量的指针
{
          int a = 10;
          const int *p = &a; //该指针只能指向常量
          //*p = 20;//不能通过*p的方法修改一个const指针
          a = 20;
          printf("a = %d\n", *p); //*p只能读，不能修改

          system("pause");
          return 0;
}

int main6() //常量指针
{
          int a = 10;
          int b = 20;
          int *const p = &a; //定义一个常量指针，可以通过常量指针修改或者读取一个变量的值
          *p = 20;
          //p = &b;//错误！常量指针一旦定义，就不能修改其指向的变量
          printf("a = %d\n", *p);

          system("pause");
          return 0;
}
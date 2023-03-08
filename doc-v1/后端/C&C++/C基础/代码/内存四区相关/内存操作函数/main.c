#include <stdio.h>
#include <string.h>

int main1()
{
          int buf[10] = {0}; //

          int i;
          /*
	参数:1-要设置的内存地址，2-设置的值，3-内存的大小（单位：字节）
	作用：将一块内存初始化为0
	*/
          memset(buf, 0, sizeof(buf));

          buf[0] = 2;
          buf[1] = 3;
          buf[4] = 9;

          for (i = 0; i < 10; i++)
          {
                    printf("buf[%d] = %d\n", i, buf[i]);
          }

          system("pause");
          return 0;
}

int main2()
{
          int i;
          int buf1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          int buf2[10] = {0};
          /*
	参数:1-拷贝到的内存地址，2-被拷贝的内存地址，3-拷贝的大小（单位：字节）
	作用：将buf1的内存内容拷贝到buf2
	*/
          //memcpy(buf2, buf1, sizeof(buf1));
          memmove(buf2, buf1, sizeof(buf1));

          for (i = 0; i < 10; i++)
          {
                    printf("buf1[%d] = %d\n", i, buf1[i]);
                    printf("buf2[%d] = %d\n", i, buf2[i]);
          }

          system("pause");
          return 0;
}

int main3()
{
          int *p[3]; //定义一个指针数组，有3个成员，每个成员都是int *
          int a = 1;
          int b = 2;
          int c = 3;

          p[0] = &a;
          p[1] = &b;
          p[2] = &c;

          *p[0] = 10; //通过指针数组成员访问指针指向内存的值
          printf("a=%d\n", a);

          *p[1] = 20;
          printf("b=%d\n", b);

          //int(*p)[3];//定义一个指向数组的指针，数组指针大多数是指向一个二维数组

          int buf1[5][3];
          int buf[2][3]; //只要二维数组的第一维是int [3]这种类型，就可以用int (*p)[3]来指向

          system("pause");
          return 0;
}

int main4()
{
          int buf[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
          int(*p)[4];
          p = buf;

          printf("%p, %p, %p, %p, %p\n", buf, buf[0], &buf[0][0], p, *p);
          p++;
          printf("%u, %u, %u, %u, %u\n", buf, buf[1], &buf[1][0], p, *p);
          printf("%u, %u\n", (p + 1), (*p + 1));

          system("pause");
          return 0;
}
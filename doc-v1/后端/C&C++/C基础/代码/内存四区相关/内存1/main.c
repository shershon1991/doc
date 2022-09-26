#include <stdio.h>

int a = 20; //全局变量

void test1()
{
          auto int a1 = 0; //不写autoC语言默认变量都是auto
}

void test2()
{
          int a2 = 0;
}

int main1()
{
          int a = 0;
          //a1 = 100;错误，因为a1的作用域在test1里面
          a = 10;
          {
                    int a = 100;
          }

          printf("a = %d\n", a);

          system("pause");
          return 0;
}

void mystatic()
{
          static int a = 0; //静态变量，只初始化一次，且程序运行期间静态变量一直存在
          printf("a = %d\n", a);
          a++;
}

int main()
{
          //register int i = 0;//建议。如果有寄存器空闲，那么这个变量就放到寄存器里面使用
          //int *p = &i;//对于一个register变量，是不能取地址操作的

          printf("----------------\n");
          int i;
          for (i = 0; i < 10; i++)
          {
                    mystatic();
          }

          system("pause");
          return 0;
}
#include <stdio.h>
#include <stdlib.h>

print_array(int *p, int n)
{
          int i;
          for (i = 0; i < n; i++)
          {
                    printf("p[%d] = %d\n", i, p[i]);
          }
}

int *geta() //错误，不能将一个栈变量的地址通过函数的返回值返回
{
          int a = 0;
          return &a;
}

int *geta1() //可以通过函数的返回值返回一个堆地址，但是要free
{
          int *p = malloc(sizeof(int)); //申请了一个堆空间
          return p;
}

int *geta2()
{
          static int a = 0;
          return &a;
}

int main1()
{
          int *getp = geta1();
          *getp = 100;
          free(getp);

          int *p = (int *)malloc(sizeof(int) * 10); //在堆中申请内存，10个int大小

          //memset(p, 0, sizeof(int) * 10);
          int i;
          for (i = 0; i < 10; i++)
          {
                    p[i] = i;
          }
          print_array(p, 10);

          char *p1 = malloc(sizeof(char) * 10); //在堆中申请了一个10个char这么大的空间

          free(p); //释放通过malloc分配的内存
          free(p1);

          printf("hello world\n");
          return 0;
}

void getheap(int *p)
{
          p = malloc(sizeof(int) * 10);
}

int main2()
{
          int i = 0;
          //scanf("%d", &i);
          int *array = malloc(sizeof(int) * i); //在堆当中动态创建一个数组

          free(array);

          int *p = NULL;
          getheap(p);
          //p = malloc(sizeof(int) * 10);
          p[0] = 1;
          p[1] = 2;

          printf("p[0] = %d, p[1] = %d\n", p[0], p[1]);

          free(p);
          return 0;
}

int main()
{
          while (1)
          {
                    int *p = malloc(1024 * 4);
                    getchar();
          }
          return 0;
}
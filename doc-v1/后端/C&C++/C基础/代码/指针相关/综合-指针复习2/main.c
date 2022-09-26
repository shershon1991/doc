#include <stdio.h>
#include <string.h>

void test(int *p)
{
          *p = 100;
}

void test1(const int p[]) //当一个数组名作为函数的参数，那么这个数组名就是一个指针变量
{
          int i = 0;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", p[i]);
          }
}

void test2(int (*p)[3]) //将多维数组作为函数的参数不常见
{
}

int main1()
{
          int i = 70;
          test(&i);
          printf("i = %d\n", i);
          printf("----------------------\n");

          int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          test1(array);

          int array2[5][3] = {0};
          test2(array2);

          void (*p2)(int *);
          p2 = test;
          int a = 10;
          p2(&a); //通过指针间接地调用了test函数
          return 0;
}

int main()
{
          int array1[5] = {1, 2, 3, 4, 5};
          int array2[5] = {0};
          memcpy(array2, array1, sizeof(array1)); //将数组1的内容拷贝到数组2里面
          memset(array1, 0, sizeof(array1));
}
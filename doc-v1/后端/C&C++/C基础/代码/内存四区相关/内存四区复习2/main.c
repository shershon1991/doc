#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996);

int *get_mymax();
void print_mymax();

int main()
{
          int *p1 = calloc(100, sizeof(int)); //同calloc(sizeof(int),100)
          if (p1 == NULL)                     //没有堆内存可以分配了，这时的错误是致命的
          {
                    exit(0);
          }

          int *p2 = realloc(p1, sizeof(int) * 200);

          memset(p2 + 100, 0, sizeof(int) * 100);

          //int set[1000000];//栈溢出
          int *set = malloc(sizeof(int) * 1000000); //在堆中创建超大数组

          int i = 0;
          scanf("%d", &i);
          //int array[i];//动态数组
          int *array = malloc(sizeof(int) * i); //在堆中创建一个动态数组

          //根据用户的输入来使用动态数组
          free(array);

          int *p = get_mymax();
          *p = 300;
          print_mymax();

          system("pause");
          return 0;
}
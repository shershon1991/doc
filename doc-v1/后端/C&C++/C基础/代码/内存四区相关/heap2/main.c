#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
          //char *p = malloc(10);//在酒店开房，酒店没有做清洁
          char *p1 = calloc(10, sizeof(char)); //在酒店开房，酒店做好清洁
          //memset(p,0,10);

          //char *p2 = realloc(p1, 20);//在原有内存基础之上，在堆中增加连续的内存
          //如果原有内存没有连续的空间可以扩展，那么就会新分配一个空间，将原有内存copy到新空间，然后释放原有内存
          //realloc和malloc一样，只是分配内存，但是不打扫
          //char *p2 = calloc(10, sizeof(char));
          char *p2 = realloc(NULL, 5); //等于malloc(5);

          int i;
          for (i = 0; i < 20; i++)
          {
                    printf("%d\n", p2[i]);
          }

          free(p2);
          return 0;
}
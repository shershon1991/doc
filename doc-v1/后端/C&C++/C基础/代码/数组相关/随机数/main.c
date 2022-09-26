#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
          time_t tm = time(NULL); //得到系统时间
          srand(tm);              //随机数种子发生器
          int i = 0;
          for (i = 0; i <= 10; i++)
          {
                    int value = rand(); //随机数产生函数
                    printf("%d\n", value);
          }

          return 0;
}
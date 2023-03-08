#include <stdio.h>

int main()
{
          int buf[2][3] = {{1, 2, 3}, {4, 5, 6}};

          //int *p[3];//指针数组
          int(*p)[3]; //定义一个指针，指向int [3]这种数据类型，指向二维数组的指针
          p = buf;    //
          printf("%d\n", sizeof(p));
          printf("%d, %d\n", p, p + 1); //位移了1*sizeof(int [3])个字节

          int i;
          int j;
          for (i = 0; i < 2; i++)
          {
                    for (j = 0; j < 3; j++)
                    {
                              printf("%d\n", p[i][j]);
                              printf("%d\n", *(*(p + i) + j));
                    }
          }

          system("pause");
          return 0;
}
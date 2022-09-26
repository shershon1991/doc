#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main()
{
          int i = 0;
          scanf("%d", &i);
          int *p = calloc(i, sizeof(int));
          int a;
          for (a = 0; a < i; a++)
          {
                    scanf("%d", &p[a]);
          }

          for (a = 0; a < i; a++)
          {
                    printf("p[%d] = %d\n", a, p[a]);
          }

          //求数组中第二大元素的值
          int max = p[0];
          int smax;

          //1.假设数组中第0个元素和第1个元素是最大和第二大
          if (p[0] > p[1])
          {
                    max = p[0];
                    smax = p[1];
          }
          else
          {
                    max = p[1];
                    smax = p[0];
          }

          for (a = 2; a < i; a++)
          {
                    if (max < p[a])
                    {
                              smax = max;
                              max = p[a];
                    }
                    else if (max > p[a] && smax < p[a])
                    {
                              smax = p[a];
                    }
          }

          printf("smax = %d\n", smax);
          return 0;
}
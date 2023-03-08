#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int sort(char **myp1 /*in*/, int num1, char (*myp2)[30], int num2, char ***myp3, int *num3)
{
          int i, j, k = 0;
          char **p3 = NULL;
          p3 = (char **)malloc((num1 + num2) * sizeof(char *));
          if (p3 == NULL)
          {
                    return -1;
          }

          return 0;
}

void sortFree11(char **p, int len)
{
          int i = 0;
          if (p == NULL)
          {
                    return;
          }

          for (i = 0; i < len; i++)
          {
                    free(p[i]);
          }
          free(p);
}

void sortFree12(char ***myp, int len)
{
          int i = 0;
          char **p = NULL;
          if (myp == NULL)
          {
                    return;
          }

          p = *myp; //还原成二级指针
          if (p == NULL)
          {
                    return;
          }

          for (i = 0; i < len; i++)
          {
                    free(p[i]);
          }
          free(p);

          *myp = NULL; //间接赋值是指针存在的最大意义
}

int main11()
{
          int ret = 0;
          char *p1[] = {"aaaaa", "ccccc", "bbbbb"};
          char buf2[10][30] = {"11111", "33333", "22222"};
          char **p3 = NULL;
          int len1, len2, len3;

          len1 = sizeof(p1) / sizeof(*p1);
          len2 = 3;

          ret = sort(p1, len1, buf2, len2, &p3, &len3);
          if (ret != 0)
          {
                    printf("func sort() err:%d \n", ret);
                    return ret;
          }

          system("pause");
          return ret;
}

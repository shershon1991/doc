#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getMem41(char **myp1 /*out*/, int *mylen1 /*out*/, char **myp2 /*out*/, int *mylen2 /*out*/)
{
          int ret = 0;
          char *tmp1, *tmp2;

          tmp1 = (char *)malloc(100);
          strcpy(tmp1, "123456");
          *mylen1 = strlen(tmp1); //一级指针的间接赋值
          *myp1 = tmp1;           //二级指针的间接赋值

          tmp2 = (char *)malloc(200);
          strcpy(tmp2, "abcdefghi");
          *mylen2 = strlen(tmp2); //一级指针的间接赋值
          *myp2 = tmp2;           //二级指针的间接赋值

          return ret;
}

int getMem42(int num)
{
          char *tmp1;

          tmp1 = (char *)malloc(num);
          strcpy(tmp1, "123456");

          return tmp1;
}

void main41()
{
          int ret = 0;
          char *p1 = NULL;
          int len1 = 0;
          char *p2 = NULL;
          int len2 = 0;

          ret = getMem41(&p1 /*out*/, &len1 /*out*/, &p2 /*out*/, &len2 /*out*/);
          if (ret != 0)
          {
                    printf("func getMem41() error:%d \n", ret);
                    return ret;
          }
          printf("p1:%s \n", p1);
          printf("p2:%s \n", p2);
          printf("len1:%d \n", len1);
          printf("len2:%d \n", len2);
          if (p1 != NULL)
          {
                    free(p1);
                    p1 = NULL;
          }
          if (p2 != NULL)
          {
                    free(p2);
                    p2 = NULL;
          }

          p1 = getMem42(100);
          printf("p1:%s \n", p1);
          if (p1 != NULL)
          {
                    free(p1);
                    p1 = NULL;
          }
          printf("p1:%d \n", p1);

          system("pause");
          return ret;
}
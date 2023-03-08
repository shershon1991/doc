#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getContentLen11(const char *fileName, char **buf, int *len)
{
          int ret = 0;
          char *tmp = NULL;
          tmp = (char *)malloc(100);
          if (tmp == NULL)
          {
                    ret = -1;
                    printf("func getContentLen11() err:%d \n", ret);
                    return ret;
          }
          strcpy(tmp, "aaaaaaa");
          *len = 10;
          *buf = tmp; //间接赋值

          return ret;
}

int getContentLen12(const char *fileName, char *buf, int *len)
{
          int ret = 0;

          if (buf == NULL)
          {
                    *len = 10;
          }
          else
          {
                    strncpy(buf, "bbbbbbbbb", *len);
          }

          return ret;
}

void main11()
{
          const char *fileName = "c:/1.txt";
          char *p = NULL;
          int len = 0;

          getContentLen11(fileName, &p, &len);
          printf("调用getContentLen11后p:%s \n", p);
          if (p != NULL)
          {
                    free(p);
                    p = NULL;
          }

          //第一次调用求长度
          getContentLen12(fileName, NULL, &len);
          p = (char *)malloc(len);
          if (p == NULL)
          {
                    return;
          }
          //第二次调用求内容
          getContentLen12(fileName, p, &len);
          printf("调用getContentLen12后p:%s \n", p);
          if (p != NULL)
          {
                    free(p);
                    p = NULL;
          }

          system("pause");
          return;
}

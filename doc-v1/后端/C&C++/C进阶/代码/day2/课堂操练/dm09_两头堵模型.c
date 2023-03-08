#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main91()
{
          //求非空格的字符串长度
          char *p = "    abcdefg    ";
          int ncount = 0;

          int i, j = 0;
          i = 0;
          j = strlen(p) - 1;

          while (isspace(p[i]) && p[i] != '\0')
          {
                    i++;
          }
          while (isspace(p[j]) && p[j] != '\0')
          {
                    j--;
          }
          ncount = j - i + 1;
          printf("ncount:%d\n", ncount);

          printf("hello...\n");
          system("pause");
          return 0;
}

int getCount2(char *str, int *pCount)
{
          int ret = 0;
          //求非空格的字符串长度
          char *p = str;
          int ncount = 0;

          if (str == NULL || pCount == NULL)
          {
                    return -1;
          }

          int i, j = 0;
          i = 0;
          j = strlen(p) - 1;

          while (isspace(p[i]) && p[i] != '\0')
          {
                    i++;
          }
          while (isspace(p[j]) && p[j] != '\0')
          {
                    j--;
          }
          ncount = j - i + 1;
          *pCount = ncount;

          return ret;
}

//去除字符串前后空格
int trimSpace(char *str, char *newStr)
{
          int ret = 0;
          char *p = str;
          int ncount = 0;
          if (str == NULL || newStr == NULL)
          {
                    return -1;
          }

          int i, j = 0;
          i = 0;
          j = strlen(p) - 1;

          while (isspace(p[i]) && p[i] != '\0')
          {
                    i++;
          }
          while (isspace(p[j]) && p[j] != '\0')
          {
                    j--;
          }
          ncount = j - i + 1;
          strcpy(newStr, str + i, ncount);
          newStr[ncount] = '\0';

          return ret;
}

void main92()
{
          int ret, ret2;
          char *p = "    abcdefg    ";
          char buf[1024] = {0};
          int num = 0;

          ret = getCount2(p, &num);
          ret2 = trimSpace(p, buf);

          if (ret != 0)
          {
                    printf("func getCount2 err:%d \n", ret);
          }
          if (ret2 != 0)
          {
                    printf("func trimSpace err:%d \n", ret2);
          }

          printf("num:%d \n", num);
          printf("buf:%s \n", buf);

          system("pause");
          return;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//char *p = "abcd1235abcd5432abcd3242";
//求字符串p中abcd出现的次数
void main81()
{
          int ncount = 0;
          //初始化，让p指针达到查找的条件
          char *p = "abcd1235abcd5432abcd3242";

          do
          {
                    p = strstr(p, "abcd");
                    if (p != NULL)
                    {
                              ncount++;
                              p = p + strlen("abcd");
                    }
                    else
                    {
                              break;
                    }
          } while (*p != '\0');

          printf("ncount:%d\n", ncount);
          printf("hello...\n");
          system("pause");

          return;
}

void main82()
{
          int ncount = 0;
          //初始化，让p指针达到查找的条件
          char *p = "abcd1235abcd5432abcd3242";

          while (p = strstr(p, "abcd"))
          {
                    ncount++;
                    p = p + strlen("abcd");
                    if (*p == '\0')
                    {
                              break;
                    }
          }

          printf("ncount:%d\n", ncount);
          printf("hello...\n");
          system("pause");
          return;
}

//1.请自定义函数接口，完成上述要求
//2.自定义的业务函数和main函数必须分开
int getCount(char *mystr /*in*/, char *sub /*in*/, int *ncount)
{
          int ret = 0;
          int tmpCount = 0;
          char *p = mystr; //不要轻易改变形参的值

          if (mystr == NULL || sub == NULL || ncount == NULL)
          {
                    ret = -1;
                    printf("func getCount() err:%d (mystr == NULL || sub == NULL || ncount == NULL) \n", ret);
                    return ret;
          }

          do
          {
                    p = strstr(p, sub);
                    if (p != NULL)
                    {
                              tmpCount++;
                              p = p + strlen(sub);
                    }
                    else
                    {
                              break;
                    }
          } while (*p != '\0');

          *ncount = tmpCount; //间接赋值是指针存在的最大意义
          return ret;
}

int main83()
{
          int ret, count;
          ret = count = 0;
          char *p = "abcd1235abcd5432abcd3242";
          char sub[] = "abcd";

          ret = getCount(p, sub, &count);
          if (ret != 0)
          {
                    printf("func getCount() err:%d\n", ret);
                    return ret;
          }
          printf("count:%d \n", count);

          system("pause");
          return 0;
}
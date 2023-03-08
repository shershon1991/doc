#include <stdio.h>
#pragma warning(disable : 4996)

int main1()
{
          FILE *p = fopen("C:\\temp\\a.txt", "r");
          if (p == NULL)
          {
                    printf("error\n");
          }
          else
          {
                    char c = 0;
                    while ((c = getc(p)) != EOF) //EOF代表文件最后的一个结束标示
                    {
                              //c = getc(p);//一次只能读取一个字符
                              printf("%c", c);
                    }
                    fclose(p);
          }

          system("pause");
          return 0;
}

int main2()
{
          FILE *p = fopen("C:\\temp\\a.txt", "w");
          if (p == NULL)
          {
                    printf("error\n");
          }
          else
          {
                    putc('a', p);
                    putc('b', p);
                    putc('c', p);
                    fclose(p);
          }

          system("pause");
          return 0;
}

#define SEC 5
int main3() //加密
{
          FILE *p = fopen("C:\\temp\\a.txt", "r");
          FILE *p1 = fopen("C:\\temp\\b.txt", "w");
          if (p == NULL)
          {
                    printf("error\n");
          }
          else
          {
                    char c = 0;
                    while ((c = getc(p)) != EOF) //EOF代表文件最后的一个结束标示
                    {
                              c += SEC;
                              putc(c, p1);
                    }
                    fclose(p);
                    fclose(p1);
          }

          system("pause");
          return 0;
}

int main4() //解密
{
          FILE *p = fopen("C:\\temp\\b.txt", "r");
          FILE *p1 = fopen("C:\\temp\\c.txt", "w");
          if (p == NULL)
          {
                    printf("error\n");
          }
          else
          {
                    char c = 0;
                    while ((c = getc(p)) != EOF) //EOF代表文件最后的一个结束标示
                    {
                              c -= SEC;
                              putc(c, p1);
                    }
                    fclose(p);
                    fclose(p1);
          }

          system("pause");
          return 0;
}

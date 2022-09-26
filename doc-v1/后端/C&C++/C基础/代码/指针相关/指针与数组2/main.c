#include <stdio.h>

void bubble(int *s) //冒泡排序
{
          int i;
          int j;
          for (i = 0; i < 10; i++)
          {
                    for (j = 0; j < 10 - i; j++)
                    {
                              if (*(s + j) < *(s + j - 1))
                              {
                                        int tmp = *(s + j);
                                        *(s + j) = *(s + j - 1);
                                        *(s + j - 1) = tmp;
                              }
                    }
          }
}

int max(int *s) //其求数组中最大元素
{
          int value = *s;
          int i;
          for (i = 1; i < 10; i++)
          {
                    if (value < *(s + i))
                    {
                              value = *(s + i);
                    }
          }
          return value;
}

int smax() //求数组中的第二大元素
{
          int buf[10] = {1, 2, 3, 4, 111, 6, 7, 8, 9, 1231};
          int max;
          int s_max;
          if (*buf > *(buf + 1))
          {
                    max = *buf;
                    s_max = *(buf + 1);
          }
          else
          {
                    max = *(buf + 1);
                    s_max = *buf;
          }

          int i;
          for (i = 2; i < 10; i++)
          {
                    if (*(buf + i) > max)
                    {
                              s_max = max;
                              max = *(buf + i);
                    }
                    else if (max > *(buf + i) && *(buf + i) > s_max)
                    {
                              s_max = *(buf + i);
                    }
          }
          return s_max;
}

void print_buf(int *s)
{
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", *(s + i));
          }
}

int main1()
{
          printf("%d\n", smax());

          int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          printf("%d\n", max(buf));

          bubble(buf);

          int *start = &buf[0];
          int *end = &buf[9];
          while (start < end)
          {
                    int tmp = *start;
                    *start = *end;
                    *end = tmp;
                    start++;
                    end--;
          }
          print_buf(buf);

          int *p = buf;
          int *p1 = &buf[1];

          printf("%d, %d\n", p, p1);
          p++;
          printf("%d\n", p);

          system("pause");
          return 0;
}

#include <string.h>
int main()
{
          char str[100] = "you good me too";
          char str2[100] = "你好我也好";
          //对于VS的汉字是GBK编码，一个汉字=2字节；对于QT汉字是UTF-8编码，一个汉字=3字节

          char *str_start = &str[0];
          char *str_end = &str[strlen(str) - 1];
          while (str_start < str_end)
          {
                    char tmp = *str_start;
                    *str_start = *str_end;
                    *str_end = tmp;
                    str_start++;
                    str_end--;
          }
          printf("%s\n", str);

          //通过指针将汉字字符串逆置
          short *str_start2 = &str2[0];
          short *str_end2 = &str2[strlen(str2) - 2];
          while (str_start2 < str_end2)
          {
                    short tmp = *str_start2;
                    *str_start2 = *str_end2;
                    *str_end2 = tmp;
                    str_start2++;
                    str_end2--;
          }
          printf("%s\n", str2);

          system("pause");
          return 0;
}

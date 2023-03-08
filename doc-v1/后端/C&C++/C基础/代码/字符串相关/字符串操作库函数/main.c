#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//追加字符串
int main1()
{
          char s[20] = "hello world";
          int len = strlen(s); //得到字符串的长度，返回一个有效字符的数量，不包含字符串结尾的0
          printf("%d\n", len);

          char s1[100] = "abcdefgdfg";
          //strcat(s, s1);//将参数2追加到参数1后面，strcat也存在缓冲区溢出的情况
          strncat(s, s1, 6); //可以限制追加字符的个数
          printf("%s\n", s);

          return 0;
}

//比较字符串
int main2()
{
          char s1[100] = "hello";
          char s2[100] = "helloabc";

          if (strncmp(s1, s2, 5) == 0) //只比较指定数量的字符
          //if (strcmp(s1, s2) == 0)//比较所有的字符，相同为0
          {
                    printf("相同\n");
          }
          else
          {
                    printf("不相同\n");
          }
          return 0;
}

//将字符串转化为整数
int main()
{
          char s[100] = "1231";

          int len = 0;
          while (s[len++])
                    ;
          len--;

          int value = 0; //存放将字符串转化为整数后的变量
          int i;
          int tmp = len;
          for (i = 0; i < len; i++) //遍历字符串
          {
                    int base = 10; //求10的n次方
                    if ((tmp - i - 1) == 0)
                    {
                              base = 1;
                    }
                    else
                    {
                              int j;
                              for (j = 1; j < (tmp - i - 1); j++)
                              {
                                        base *= 10;
                              }
                    }
                    value += (base * (s[i] - '0'));
          }

          printf("%d\n", value);
          return 0;
}
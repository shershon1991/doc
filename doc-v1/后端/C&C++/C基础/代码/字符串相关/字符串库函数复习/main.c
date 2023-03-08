#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main1()
{
          char s[100] = "hello world";
          //int len = strlen(s);
          size_t len = strlen(s); //size_t是unsigned int类型

          printf("%d\n", len);
          return 0;
}

int main2()
{
          char s1[100] = "baaa";
          char s2[100] = "bddd";
          printf("%d\n", strcmp(s1, s2)); //比较两个参数的ASCII码s1>s2 1  s1<s2 1  s1=s2  0

          sprintf(s1, "hello world");
          printf("%s\n", s1);
          return 0;
}

int main3()
{
          char s1[100] = "abcd";
          sprintf(s1, "123,456");
          int a = 0;
          int b = 1;
          sscanf(s1, "%d, %d", &a, &b);
          printf("%d\n", a);
          printf("%d\n", b);
          return 0;
}

int main4()
{
          char s[100] = "345";
          int i = atoi(s);
          return 0;
}

void myitoa(int n, char s[])
{
          int status = 0; //0代表正数，1代表负数
          if (n < 0)
          {
                    status = 1;
                    n = 0 - n;
          }
          int i = 0;

          while (n)
          {
                    int a = n % 10;   //取出整数的个位数
                    char c = a + '0'; //将整数转化为字符
                    s[i] = c;         //将转化后的char依次放入字符串s中
                    i++;
                    n = n / 10;
          }

          int min = 0;
          int max = i - 1;
          while (min < max)
          {
                    char tmp = s[min];
                    s[min] = s[max];
                    s[max] = tmp;
                    min++;
                    max--;
          }

          if (status == 1) //如果是负数，字符串每一位向后移动一位，然后将字符串的开始置为‘-’
          {
                    int len = 0;
                    for (len = i - 1; len >= 0; len--)
                    {
                              s[len + 1] = s[len];
                    }
                    s[0] = '-';
          }
}

int main()
{
          int i = -456;
          char s[100] = {0};
          myitoa(i, s);

          printf("%s\n", s);
          return 0;
}
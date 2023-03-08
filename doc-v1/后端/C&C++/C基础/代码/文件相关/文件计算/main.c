#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int calc_string(const char *s) //得到字符串计算的值
{
          char buf1[100] = {0};
          char operatar1 = 0;
          char buf2[100] = {0};

          int len = strlen(s);

          int i;
          for (i = 0; i < len; i++)
          {
                    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                    {
                              strncpy(buf1, s, i);
                              operatar1 = s[i];
                              break;
                    }
          }

          int start = i + 1;
          for (; i < len; i++)
          {
                    if (s[i] == '=')
                    {
                              strncpy(buf2, &s[start], i - start);
                    }
          }

          //printf("buf1 = %s, oper1 = %c, buf2 = %s\n", buf1, operatar1, buf2);

          switch (operatar1)
          {
          case '+':
                    return atoi(buf1) + atoi(buf2);
          case '-':
                    return atoi(buf1) - atoi(buf2);
          case '*':
                    return atoi(buf1) * atoi(buf2);
          case '/':
          {
                    int a = atoi(buf2);
                    if (a)
                              return atoi(buf1) / atoi(buf2);
                    else
                              return 0;
          }
          }
}

void cutereturn(char *s) //把字符串最后的回车字符吃掉
{
          int len = strlen(s);
          if (s[len - 1] == '\n')
                    s[len - 1] = 0;
}

int main()
{
          //const char *s = "32 / 0 =";
          //printf("%d\n", calc_string(s));
          //return 0;
          FILE *p = fopen("C:\\temp\\a.txt", "r");
          FILE *p1 = fopen("C:\\temp\\b.txt", "w");
          char buf[1024];
          char buf1[1024];

          while (!feof(p))
          {
                    memset(buf, 0, sizeof(buf));
                    fgets(buf, sizeof(buf), p);
                    cutereturn(buf);
                    int value = calc_string(buf);
                    memset(buf1, 0, sizeof(buf1));
                    sprintf(buf1, "%s%d\n", buf, value);
                    //printf("buf1 = %s\n",buf1);
                    fputs(buf1, p1);
          }
          fclose(p);
          fclose(p1);
          return 0;
}
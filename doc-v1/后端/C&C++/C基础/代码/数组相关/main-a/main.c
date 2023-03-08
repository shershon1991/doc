#include <stdio.h>

int main1(int argc, char *args[])
{
          printf("%d\n", argc);
          //argc代表程序执行的时候有几个参数，程序名称本身就是一个参数，所以argc最小为1
          printf("args[0] = %s\n", args[0]);
          return 0;
}

int main(int argc, char *args[])
{
          if (argc < 4)
          {
                    printf("参数不足，程序退出\n");
                    return 0;
          }
          int a = atoi(args[1]);
          int b = atoi(args[3]);

          char *s = args[2];
          char c = s[0];

          switch (c)
          {
          case '+':
                    printf("%d\n", a + b);
                    break;
          case '-':
                    printf("%d\n", a - b);
                    break;
          case '*':
                    printf("%d\n", a * b);
                    break;
          case '/':
                    if (b)
                    {
                              printf("%d\n", a * b);
                    }
                    break;
          }
          return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//字符数组
int main1()
{
          //char arr[10] = { 'a','b','c','d' };
          char arr[10] = "abcd";
          //char arr[] = "abcd";
          //char arr[10] = {0};
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%c ", arr[i]);
          }

          system("pause");
          return 0;
}

//rand、srand
int main2()
{
          int i;
          int t = (int)time(NULL);
          srand(t);
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", rand());
          }

          system("pause");
          return 0;
}

//使用scanf输入字符串
int main3()
{
          char s[10];
          scanf("%s", s); //"%s"的作用就是输入一个字符串,scanf以回车键作为输入结束标示，但回车键本身不会作为字符串的一部分
          //如果scanf参数中的数组长度小于用户在键盘输入的长度，那么scanf就会缓冲区溢出，导致程序崩溃
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", s[i]);
          }
          printf("-----------------------------\n");
          printf("%s\n", s);
          system("pause");
          return 0;
}

/*------字符串处理函数-------*/
//gets
int main4()
{
          char s[10];
          gets(s); //回车是输入结束标志，空格不是，可以使用gets输入带空格的字符串
          //gets和scanf一样，也存在缓冲区溢出的问题
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", s[i]);
          }
          printf("-----------------------\n");
          printf("%s\n", s);

          system("pause");
          return 0;
}

//fgets
int main5()
{
          char s[10] = {0};
          fgets(s, sizeof(s) - 1, stdin); //fgets是安全的，不存在缓冲区溢出的问题
          printf("%s\n", s);

          system("pause");
          return 0;
}

//puts
int main6()
{
          char s[100] = "hello wrold";
          //printf("%s", s);
          puts(s); //puts会自动在输出完成之后打印一个"\n"

          system("pause");
          return 0;
}

//fputs
int main7()
{
          char s[] = "hello world";
          fputs(s, stdout);

          system("pause");
          return 0;
}

void main8()
{
          int a = 0;
          int b = 0;
          char c;
          char d[10];

          //scanf("%d", &a);
          //scanf("%d", &b);
          //c = getchar();
          gets(d);

          //printf("a:%d,b:%d", a, b);
          //printf("c:%c", c);
          printf("d:%s", d);

          system("pause");
          return;
}

void main()
{
          char s[100] = "hello world";
          char *p = s;
          *(p + 0) = 'b';
          p += 5;
          *p = 'a';

          printf("%s\n", s);

          system("pause");
          return;
}
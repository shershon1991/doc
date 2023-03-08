#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main1()
{
          char s[2048] = {0};
          scanf("%s", s); //"%s"的作用就是输入一个字符串,scanf以回车键作为输入结束标示，但回车键本身不会作为字符串的一部分
          //如果scanf参数中的数组长度小于用户在键盘输入的长度，那么scanf就会缓冲区溢出，导致程序崩溃
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", s[i]);
          }
          printf("-----------------------------\n");
          printf("%s\n", s);
          return 0;
}

int main2()
{
          char s[100] = {0};
          gets(s); //gets认为回车是输入结束标志，空格不是，所有用gets就可以输入带空格的字符串
          //gets和scanf一样存在缓冲区溢出的问题

          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("%d\n", s[i]);
          }
          printf("-----------------------------\n");
          printf("%s\n", s);
          return 0;
}

int main3()
{
          /*int a = 0;
	int b = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d\n", a + b);*/

          char a[100] = {0};
          char b[100] = {0};

          gets(a);
          gets(b);

          int i1 = atoi(a); //将字符串转换成一个整数
          int i2 = atoi(b); //将字符串转换成一个整数
          printf("%d\n", i1 + i2);
          return 0;
}

int main()
{
          char s[100] = {"hello world"};
          //fgets(s, sizeof(s) - 1, stdin);//1-char数组 2-数组的大小，字节 3-代表标准输入
          //fgets是安全的，不存在缓冲区溢出的问题
          //printf("%s\n", s);
          puts(s); //puts函数自动会在输出完成之后打印一个'\n'
          return 0;
}
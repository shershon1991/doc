#include <stdio.h>

void print_array(int *p, int n) //如果参数是一个int数组，那么就会传递第二个参数，用来标识数组的长度
{
          int i;
          for (i = 0; i < n; i++)
          {
                    printf("p[%d] = %d\n", i, p[i]);
          }
}

void print_str(char *s) //如果参数是一个字符串，那么就不需要第二个参数，因为字符串是明确的以‘\0’结尾的
{
          int i = 0;
          while (s[i])
          {
                    printf("%c", s[i++]);
          }
}

void print_str_a(char *s, int n)
{
          int i;
          for (i = 0; i < n; i++)
          {
                    printf("%c", s[i]);
          }
}

int main()
{
          char s[100] = "hello world";
          s[3] = 0;
          //print_str(s);
          print_str_a(s, sizeof(s));
          return 0;

          int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

          print_array(array, 10);
          return 0;

          char buf[100] = "hello world";
          char *p = buf;
          //*(p + 5) = 'a';
          //p[5] = 'b';
          p += 5;
          *p = 'c';
          p[3] = ' ';
          printf("%s\n", buf);
          return 0;
}
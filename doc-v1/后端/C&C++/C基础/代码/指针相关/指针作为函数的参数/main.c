#include <stdio.h>
#include <string.h>

void test(int *n)
{
          (*n)++;
}

int main1()
{
          int i = 100;
          test(&i);
          printf("i = %d\n", i);
          //scanf("%d", &i);//所有需要在函数内部修改实参的值，都需要通过将指针作为函数参数调用的方法实现

          int a = 10;
          int *p = &a;
          *p = 100;
          printf("a = %d\n", a);

          system("pause");
          return 0;
}

void set_array(int buf[]) //数组名代表数组的首地址
{
          buf[0] = 100;
          buf[1] = 200;
}

void print_array(const int buf[], int n) //数组名代表数组的首地址，n的作用是告诉函数内部数组的维度
//通过const标识，不改变参数的值
{
          int i;
          for (i = 0; i < n; i++)
          {
                    printf("buf[%d] = %d\n", i, buf[i]);
          }
}

void print_buf1(int (*p)[3], int a, int b) //将二维数组作为函数参数时定义的指针类型
//void print_buf1(int p[][3], int a, int b)
{
          int i;
          int j;
          for (i = 0; i < a; i++)
          {
                    for (j = 0; j < b; j++)
                    {
                              printf("p[%d][%d] = %d\n", i, j, p[i][j]);
                    }
          }
}

void mystrcat(char *s1, const char *s2) //第一个参数可以被修改，第二个参数不能被修改
{
          int len = 0;
          while (s2[len])
          {
                    len++;
          }
          while (*s1)
          {
                    s1++;
          }
          int i = 0;
          for (i = 0; i < len; i++)
          {
                    *s1 = *s2;
                    s1++;
                    s2++;
          }
}

char *mystrchr(char *s, char c)
{
          while (*s)
          {
                    if (*s == c)
                              return s;
                    s++;
          }
          return NULL;
}

int main2()
{
          char str[100] = "hello world";
          char *s = mystrchr(str, 'e');
          printf("s = %s\n", s);

          char s1[10] = "abc";
          char s2[10] = "bcd";
          mystrcat(s1, s2);
          printf("s1 = %s\n", s1);

          int buf1[3][3] = {{1, 2, 3}, {4, 5, 6}};
          print_buf1(buf1, sizeof(buf1) / sizeof(buf1[0]), sizeof(buf1[0]) / sizeof(int));

          int buf[] = {1, 2, 3, 4, 5};
          set_array(buf);
          print_array(buf, sizeof(buf) / sizeof(int));

          system("pause");
          return 0;
}

int main3()
{
          int buf1[3][5] = {{1, 2, 3, 4, 5}, {4, 5, 6, 7, 8}, {7, 8, 9, 10, 11}};
          int i;
          int j;
          for (i = 0; i < 3; i++)
          {
                    int sum = 0;
                    for (j = 0; j < 5; j++)
                    {
                              //sum += buf1[i][j];
                              sum += *(*(buf1 + i) + j);
                    }
                    printf("%d\n", sum / 3);
          }
          printf("-------\n");
          for (i = 0; i < 5; i++)
          {
                    int sum = 0;
                    for (j = 0; j < 3; j++)
                    {
                              sum += *(*(buf1 + j) + i);
                              //sum += buf1[j][i];
                    }
                    printf("%d\n", sum / 5);
          }

          system("pause");
          return 0;
}
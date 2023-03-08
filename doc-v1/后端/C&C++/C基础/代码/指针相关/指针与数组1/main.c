#include <stdio.h>

void print(char s[])
{
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("s[%d] = %d\n", i, s[i]);
          }
}

int main()
{
          char buf[10] = {0, 1, 2, 3, 4};
          char *p = buf;
          char *p1 = &buf[0];
          char *p2 = &buf[1];
          char *p3 = &buf[2];

          *p2 = 7;

          p3 += 1;
          *p3 = 100;

          p3 -= 2;
          *p3 = 20;

          printf("%d, %d, %d, %d\n", p, p1, p2, p3);

          int i;
          for (i = 0; i < 10; i++)
          {
                    *p = i;
                    p++;
          }
          print(buf);

          //p已经指向数组的最后一个成员了
          //p = buf;//将p的值重新指向了数组的首地址
          p -= 10;

          for (i = 0; i < 10; i++)
          {
                    *p = i * 10;
                    p++;
          }

          print(buf);

          system("pause");
          return 0;
}

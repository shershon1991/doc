#include <stdio.h>

int main()
{
          char s1[100] = "hello";
          char s2[100] = "world";

          //用指针求一个字符串的长度，不使用数组下标的方式
          //用指针将s1和s2合并为一个字符串，结果放入s1中，不使用数组下标的方式

          char *p1 = s1;
          int len = 0;
          while (*p1) //p1的内容为0的时候，表示字符串结束
          {
                    p1++;
                    len++;
          }

          printf("len = %d\n", len);

          char *p2 = s2;

          while (*p2)
          {
                    *p1++ = *p2++; //p1指向s1的最后一个元素，p1指向s2的第一个元素
                                   //p2++;
                                   //p1++;
          }

          printf("s1 = %s\n", s1);
          return 0;
}
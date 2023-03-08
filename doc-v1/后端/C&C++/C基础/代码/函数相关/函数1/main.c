#include <stdio.h>

int max(int a, int b);
int add(int a, int b);

int main()
{
          int c = max(200, 300);
          printf("%d\n", c);
          c = add(100, 50);
          printf("%d\n", c);
          return 0;
}
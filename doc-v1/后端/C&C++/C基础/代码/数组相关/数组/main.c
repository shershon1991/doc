#include <stdio.h>

//一维数组
int main1()
{
          int i, arr[10];
          for (i = 0; i <= 9; i++)
                    arr[i] = i;
          for (i = 9; i >= 0; i--)
                    printf("%d\n", arr[i]);
          return 0;
}

//二维数组
int main()
{
          int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
          int b[3][2], i, j;
          printf("array a:\n");
          for (i = 0; i <= 1; i++)
          {
                    for (j = 0; j <= 2; j++)
                    {
                              printf("%2d", a[i][j]);
                              b[j][i] = a[i][j];
                    }
                    printf("\n");
          }
          printf("array b:\n");
          for (i = 0; i <= 2; i++)
          {
                    for (j = 0; j <= 1; j++)
                    {
                              printf("%2d", b[i][j]);
                    }
                    printf("\n");
          }
          return 0;
}

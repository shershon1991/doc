#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

int main1()
{
          srand(time(NULL));
          int i;
          FILE *p = fopen("C:\\temp\\a.txt", "w");

          for (i = 0; i < 1000; i++)
          {
                    fprintf(p, "%d\n", (int)rand() % 513);
          }
          fclose(p);

          printf("end\n");
          return 0;
}

int main()
{
          FILE *p = fopen("C:\\temp\\a.txt", "r");
          int array[513] = {0};
          while (!feof(p))
          {
                    char buf[100] = {0};
                    fgets(buf, sizeof(buf), p);
                    if (buf[0] != 0)
                    {
                              int value = atoi(buf); //转化为整数
                              array[value]++;
                    }
          }
          fclose(p);

          p = fopen("C:\\temp\\b.txt", "w");
          int i;
          int j;
          for (i = 0; i < 513; i++)
          {
                    for (j = 0; j < array[i]; j++)
                    {
                              fprintf(p, "%d\n", i);
                    }
          }

          printf("end\n");
          return 0;
}
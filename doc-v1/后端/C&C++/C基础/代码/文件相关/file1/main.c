#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main1()
{
          FILE *p = fopen("C:\\temp\\a.txt", "r");

          while (!feof(p))
          {
                    char buf[100] = {0};
                    fscanf(p, "%s", buf); //fscanf与scanf用法基本一致,fscanf是从文件读取输入，scanf是从键盘读取输入
                    //fgets(buf, sizeof(buf), p);
                    printf("%s\n", buf);
          }
          fclose(p);

          system("pause");
          return 0;
}

int main()
{
          FILE *p = fopen("C:\\temp\\b.txt", "w");
          int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
          int i;
          for (i = 0; i < 10; i++)
          {
                    fprintf(p, "array[%d] = %d\n", i, array[i]);
          }

          char buf[100] = "hello world";
          int a = 6;
          int b = 7;
          fprintf(p, "%s, %d, %d", buf, a, b); //和printf一样，fprintf输出到文件里面，printf输出到屏幕
          fclose(p);

          system("pause");
          return 0;
}
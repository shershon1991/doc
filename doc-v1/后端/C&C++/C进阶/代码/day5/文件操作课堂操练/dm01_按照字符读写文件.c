#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//fputc
void main_fputc()
{
          int i = 0;
          FILE *fp = NULL;
          char *filename = "c:\\1.txt";
          char *filename2 = "c:/2.txt"; //统一使用45°
          char a[20] = "abcdefg";

          fp = fopen(filename2, "r+");
          if (fp == NULL)
          {
                    printf("func fopen() err:%d \n");
                    return;
          }

          printf("打开成功 \n");
          for (i = 0; i < strlen(a); i++)
          {
                    fputc(a[i], fp);
          }

          fclose(fp);

          return;
}

//fgetc
void main_fgetc()
{
          int i = 0;
          FILE *fp = NULL;
          char *filename = "c:\\1.txt";
          char *filename2 = "c:/2.txt"; //统一使用45°
          char a[20] = "abcdefg";

          fp = fopen(filename2, "r+");
          if (fp == NULL)
          {
                    printf("func fopen() err:%d \n");
                    return;
          }

          printf("打开成功 \n");
          while (!feof(fp))
          {
                    char tmpc = fgetc(fp);
                    printf("%c", tmpc);
          }

          if (fp != NULL)
          {
                    fclose(fp);
          }

          return;
}

void main11()
{
          main_fputc();
          main_fgetc();

          system("pause");
          return;
}

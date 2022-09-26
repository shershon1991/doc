#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher
{
          char name[64];
          int age;
} Teacher;

//直接把内存数据写入到文件中
void main_fwrite()
{
          int i = 0;
          int myN = 0;
          FILE *fp = NULL;
          char *fileName = "c:/3.data";
          Teacher tArray[3];

          for (i = 0; i < 3; i++)
          {
                    sprintf(tArray[i].name, "%d%d%d", i + 1, i + 1, i + 1);
                    tArray[i].age = i + 31;
          }

          fp = fopen(fileName, "wb");
          if (fp == NULL)
          {
                    printf("建立文件失败\n");
                    return;
          }

          for (i = 0; i < 3; i++)
          {
                    myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
          }

          if (fp != NULL)
          {
                    fclose(fp);
          }
}

void main_fread()
{
          int i = 0;
          int myN = 0;
          FILE *fp = NULL;
          char *fileName = "c:/3.data";
          Teacher tArray[3];

          fp = fopen(fileName, "rb");
          if (fp == NULL)
          {
                    printf("建立文件失败\n");
                    return;
          }

          for (i = 0; i < 3; i++)
          {
                    myN = fread(&tArray[i], sizeof(Teacher), 1, fp);

                    //myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
          }

          for (i = 0; i < 3; i++)
          {
                    printf("name:%s, age:%d \n", tArray[i].name, tArray[i].age);
          }

          if (fp != NULL)
          {
                    fclose(fp);
          }
}

void main31()
{
          //main_fwrite();
          main_fread();

          system("pause");
          return;
}

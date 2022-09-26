#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher
{
          char name[64];
          char *aliasname;
          int age;
          int id;
} Teacher;

void printTeacher31(Teacher *array, int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    printf("age:%d \n", array[i].age);
          }
}

void sortTeacher31(Teacher *array, int num)
{
          int i, j;
          Teacher tmp;

          for (i = 0; i < num; i++)
          {
                    for (j = i + 1; j < num; j++)
                    {
                              if (array[i].age > array[j].age)
                              {
                                        tmp = array[i];
                                        array[i] = array[j];
                                        array[j] = tmp;
                              }
                    }
          }
}

int createTeacher31(Teacher **pT, int num)
{
          int i = 0;
          Teacher *tmp = NULL;
          tmp = (Teacher *)malloc(sizeof(Teacher) * num); //Teacher Array[3]
          if (tmp == NULL)
          {
                    return -1;
          }
          memset(tmp, 0, sizeof(Teacher) * num);
          for (i = 0; i < num; i++)
          {
                    tmp[i].aliasname = (char *)malloc(60);
          }
          *pT = tmp;
          return 0;
}

void freeTeacher31(Teacher *p, int num)
{
          int i = 0;

          if (p == NULL)
          {
                    return;
          }
          for (i = 0; i < num; i++)
          {
                    if (p[i].aliasname != NULL)
                    {
                              free(p[i].aliasname);
                    }
          }
          free(p);
}

void main31()
{
          int ret = 0;
          int i = 0;
          int num = 3;
          Teacher *pArray = NULL;
          ret = createTeacher31(&pArray, num);
          if (ret != 0)
          {
                    printf("func createTeacher31() err:%d \n", ret);
          }

          for (i = 0; i < num; i++)
          {
                    printf("\n please enter age:");
                    scanf("%d", &(pArray[i].age));

                    printf("\n please enter name:");
                    scanf("%s", pArray[i].name);

                    printf("\n please enter alias:");
                    scanf("%s", pArray[i].aliasname);
          }

          printTeacher31(pArray, num);

          sortTeacher31(pArray, num);

          printf("\n");
          printTeacher31(pArray, num);

          freeTeacher31(pArray, num);

          system("pause");
          return;
}

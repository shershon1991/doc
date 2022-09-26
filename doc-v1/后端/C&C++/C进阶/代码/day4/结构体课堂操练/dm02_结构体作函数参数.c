#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher
{
          char name[64];
          int age;
          int id;
} Teacher;

void printTeacher(Teacher *array, int num)
{
          int i = 0;

          for (i = 0; i < num; i++)
          {
                    printf("age:%d \n", array[i].age);
          }
}

void sortTeacher(Teacher *array, int num)
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

//结构体数组3 输入年龄，排序
void main21()
{
          int i = 0;
          Teacher Array[3]; //在stack上分配
          int num = 3;

          for (i = 0; i < num; i++)
          {
                    printf("\n please enter age:");
                    scanf("%d", &(Array[i].age));
          }

          //打印年龄
          printTeacher(Array, num);

          sortTeacher(Array, num);

          printf("排序之后 \n");
          printTeacher(Array, num);

          system("pause");
          return;
}

Teacher *createTeacher(int num)
{
          Teacher *tmp = NULL;
          tmp = (Teacher *)malloc(sizeof(Teacher) * num); //Teacher Array[3]
          if (tmp == NULL)
          {
                    return NULL;
          }
}

void freeTeacher(Teacher *p)
{
          if (p != NULL)
          {
                    free(p);
          }
}

void main22()
{
          int i = 0;
          //Teacher Array[3];//在stack上分配
          int num = 3;
          Teacher *pArray = NULL;
          pArray = createTeacher(num);

          for (i = 0; i < num; i++)
          {
                    printf("\n please enter age:");
                    scanf("%d", &(pArray[i].age));
          }

          //打印
          printTeacher(pArray, num);

          sortTeacher(pArray, num);

          printf("排序之后 \n");
          printTeacher(pArray, num);

          freeTeacher(pArray);

          system("pause");
          return;
}

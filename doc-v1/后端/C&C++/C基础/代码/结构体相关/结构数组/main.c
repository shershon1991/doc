#include <stdio.h>
#include <string.h>

struct student
{
          char name[16];
          unsigned char age;
          unsigned char score;
          char classes[100];
};

void swap(struct student *a, struct student *b)
{
          struct student tmp = *a;
          *a = *b;
          *b = tmp;
}

int main1()
{
          struct student st[5] = {{"周永康1", 70, 56, "C++基础班"}, {"周永康2", 60, 52, "C++基础班"}, {"周永康3", 70, 59, "C++基础班"}, {"周永康4", 65, 59, "C++基础班"}, {"周永康5", 65, 90, "C++基础班"}};

          //struct student tmp = st[0];
          //st[0] = st[1];
          //st[1] = tmp;

          int i;
          int j;
          for (i = 0; i < 5; i++)
          {
                    for (j = 1; j < 5 - i; j++)
                    {
                              if (st[j].age < st[j - 1].age)
                              {
                                        swap(&st[j], &st[j - 1]);
                              }
                              else if (st[j].age == st[j - 1].age)
                              {
                                        if (st[j].score < st[j - 1].score)
                                        {
                                                  swap(&st[j], &st[j - 1]);
                                        }
                              }
                    }
          }

          for (i = 0; i < 5; i++)
          {
                    printf("姓名=%s,年龄=%d,成绩=%d,班级=%s\n", st[i].name, st[i].age, st[i].score, st[i].classes);
          }

          system("pause");
          return 0;
}

int main()
{
          struct student st[5] = {{"周永康1", 70, 56, "JAVA基础班"}, {"周永康2", 60, 52, "C++基础班"}, {"周永康3", 70, 59, "C++基础班"}, {"周永康4", 65, 59, "PHP基础班"}, {"周永康5", 65, 90, "C++基础班"}};

          int i;
          int j;
          for (i = 0; i < 5; i++)
          {
                    for (j = 1; j < 5 - i; j++)
                    {
                              if (strcmp(st[j].classes, st[j - 1].classes) > 0)
                              {
                                        swap(&st[j], &st[j - 1]);
                              }
                    }
          }

          for (i = 0; i < 5; i++)
          {
                    printf("姓名=%s,年龄=%d,成绩=%d,班级=%s\n", st[i].name, st[i].age, st[i].score, st[i].classes);
          }

          system("pause");
          return 0;
}
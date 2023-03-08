#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

struct student
{
          char name[100];
          int age;
          int sex;
}; //说明了一个结构体的数据结构类型

int main()
{
          //struct student st = {"张学友", 30, 1};//定义了一个结构体的变量，叫st

          //struct student st = {.age = 20, .sex=1};

          struct student st = {0}; //定义了一个结构体的变量，叫st，同时将所有成员的值初始化为0

          /*st.age = 20;
	st.sex = 0;
	strcpy(st.name, "刘德华");*/

          scanf("%s", st.name);
          scanf("%d", &st.age);
          scanf("%d", &st.sex);

          printf("name = %s\n", st.name);
          printf("age = %d\n", st.age);

          if (st.sex == 0)
          {
                    printf("sex = 男\n");
          }
          else
          {
                    printf("sex = 女\n");
          }

          system("pause");
          return 0;
}
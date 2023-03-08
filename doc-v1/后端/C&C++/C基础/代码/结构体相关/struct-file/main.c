#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

struct student
{
          char name[100];
          int age;
};

int main1()
{
          struct student st = {"年龄", 30};
          FILE *p = fopen("C:\\temp\\a.dat", "wb");
          fwrite(&st, sizeof(st), 1, p);
          fclose(p);

          return 0;
}

int main()
{
          struct student st = {0};
          FILE *p = fopen("C:\\temp\\a.dat", "rb");
          fread(&st, sizeof(st), 1, p);
          fclose(p);
          printf("name = %s, age = %d\n", st.name, st.age);

          return 0;
}
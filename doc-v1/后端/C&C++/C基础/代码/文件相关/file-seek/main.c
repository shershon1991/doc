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
          struct student st[10] = {0};
          int i;
          for (i = 0; i < 10; i++)
          {
                    printf("please name:");
                    scanf("%s", st[i].name);
                    printf("please age:");
                    scanf("%d", &st[i].age);
          }

          FILE *p = fopen("C:\\temp\\a.dat", "wb");
          fwrite(st, sizeof(struct student), 10, p);
          fclose(p);

          printf("end\n");
          return 0;
}

int main2()
{
          struct student st = {0};
          FILE *p = fopen("C:\\temp\\a.dat", "rb");

          //fseek(p, sizeof(struct student) * 2, SEEK_SET);//从文件开始位置向后偏移一个结构体的字节数

          memset(&st, 0, sizeof(struct student));
          fread(&st, sizeof(struct student), 1, p);
          printf("name = %s, age = %d\n", st.name, st.age);

          //fseek(p, 0 - sizeof(struct student), SEEK_CUR);//从当前位置往回偏移
          fseek(p, sizeof(struct student), SEEK_CUR); //从当前位置往后偏移

          memset(&st, 0, sizeof(struct student));
          fread(&st, sizeof(struct student), 1, p);
          printf("name = %s, age = %d\n", st.name, st.age);

          fseek(p, 0 - sizeof(struct student), SEEK_END); //从文件结尾位置往回偏移

          memset(&st, 0, sizeof(struct student));
          fread(&st, sizeof(struct student), 1, p);
          printf("name = %s, age = %d\n", st.name, st.age);

          /*while (1)
	{
		memset(&st, 0, sizeof(struct student));
		if (fread(&st, sizeof(struct student), 1, p) == 0)
			break;
		printf("name = %s, age = %d\n", st.name, st.age);
	}
	fclose(p);*/

          return 0;
}

int main()
{
          FILE *p = fopen("C:\\temp\\a.txt", "rb");
          fseek(p, -5, SEEK_END);
          char buf[100] = {0};
          fgets(buf, sizeof(buf), p);
          printf("buf = %s\n", buf);
          fclose(p);

          return 0;
}
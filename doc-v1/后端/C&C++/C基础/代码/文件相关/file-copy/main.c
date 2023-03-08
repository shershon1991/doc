#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#pragma warning(disable : 4996)

int main()
{
          clock_t c1 = clock();         //得到系统当前时间，单位：ms
          struct stat st = {0};         //定义一个结构体
          stat("C:\\temp\\a.wmv", &st); //调用stat函数之后，文件相关的信息保存在st结构中
          /*st.st_size得到文件的大小
	printf("%u\n", st.st_size);
	printf("hello world\n");*/

          char *array = malloc(st.st_size); //根据文件大小在堆中动态分配内存
          FILE *p = fopen("C:\\temp\\a.wmv", "rb");
          fread(array, sizeof(char), st.st_size, p); //把文件一次性放入内存
          fclose(p);

          p = fopen("C:\\temp\\b.wmv", "wb");
          fwrite(array, sizeof(char), st.st_size, p); //将堆中的信息一次性写入文件
          fclose(p);

          clock_t c2 = clock(); //得到系统当前时间，单位：ms
          printf("end, %u\n", c2 - c1);

          system("pause");
          return 0;
}
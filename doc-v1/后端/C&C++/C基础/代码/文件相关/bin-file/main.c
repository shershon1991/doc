#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main1()
{
          FILE *p = fopen("C:\\temp\\bin-file.exe", "rb");
          /*char buf[1024] = { 0 };
	size_t res = fread(buf, sizeof(char), sizeof(buf), p);
	printf("res = %u\n", res);

	res = fread(buf, sizeof(char), sizeof(buf), p);
	printf("res = %u\n", res);*/
          //fread的返回值代表读取了多少记录数
          while (!feof(p))
          {
                    char buf[1024] = {0};
                    int res = fread(buf, sizeof(char), sizeof(buf), p); //参数：1-缓冲区；2-最小单位大小；3-读取单位数；4-打开的文件指针
                    int i;
                    for (i = 0; i < res; i++)
                    {
                              printf("buf[%d] = %x\n", i, buf[i]);
                    }
          }
          fclose(p);

          return 0;
}

int main2()
{
          FILE *p = fopen("C:\\temp\\a.dat", "wb");
          char buf[1024] = {0};
          buf[0] = 'a';
          buf[1] = 'b';
          buf[2] = 'c';
          buf[3] = 'd';
          fwrite(buf, sizeof(char), 10, p);
          fclose(p);
}

void code(char *p, size_t n)
{
          size_t i;
          for (i = 0; i < n; i++)
          {
                    p[i] += 3;
          }
}

void decode(char *p, size_t n)
{
          size_t i;
          for (i = 0; i < n; i++)
          {
                    p[i] -= 3;
          }
}

int main() //二进制解密
{
          FILE *p = fopen("C:\\temp\\b.wmv", "rb");
          FILE *p1 = fopen("C:\\temp\\c.wmv", "wb");

          /*FILE *p = fopen("C:\\temp\\b.txt", "rb");
	FILE *p1 = fopen("C:\\temp\\c.txt", "wb");*/

          char buf[1024 * 4];
          while (!feof(p))
          {
                    memset(buf, 0, sizeof(buf));
                    size_t res = fread(buf, sizeof(char), sizeof(buf), p); //返回从源文件中读取的字节数
                    decode(buf, res);
                    fwrite(buf, sizeof(char), res, p1); //从源文件中读取多少字节就往目标文件中写入多少字节
          }
          fclose(p);
          fclose(p1);

          printf("end\n");
          return 0;
}

int main3() //二进制加密
{
          FILE *p = fopen("C:\\temp\\a.wmv", "rb");
          FILE *p1 = fopen("C:\\temp\\b.wmv", "wb");

          /*FILE *p = fopen("C:\\temp\\a.txt", "rb");
	FILE *p1 = fopen("C:\\temp\\b.txt", "wb");*/

          char buf[1024 * 4];
          while (!feof(p))
          {
                    memset(buf, 0, sizeof(buf));
                    size_t res = fread(buf, sizeof(char), sizeof(buf), p); //返回从源文件中读取的字节数
                    code(buf, res);
                    fwrite(buf, sizeof(char), res, p1); //从源文件中读取多少字节就往目标文件中写入多少字节
          }
          fclose(p);
          fclose(p1);

          printf("end\n");
          return 0;
}

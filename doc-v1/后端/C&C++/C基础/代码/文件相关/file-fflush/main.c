#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
          FILE *p = fopen("C:\\temp\\a.txt", "w");
          while (1)
          {
                    char buf[100] = {0};
                    scanf("%s", buf);
                    if (strcmp(buf, "exit") == 0)
                              break;
                    fprintf(p, "%s\n", buf);
                    fflush(p); //将缓冲区的内容立刻写入磁盘文件
                               //好处：不会因为停电、电脑死机等故障导致缓冲区内容丢失
                               //坏处：硬盘读写次数增加，导致程序效率低下、硬盘寿命变短
                               //修改配置文件的时候，有时候使用；或者不经常修改但很重要的数据，可以使用fflush
          }
          fclose(p);

          printf("end\n");
          return 0;
}

int main2()
{
          //remove("C:\\temp\\a.txt");//删除a.txt
          rename("C:\\temp\\c.txt", "C:\\temp\\a.txt"); //将c.txt重命名为a.txt

          printf("end\n");
          return 0;
}
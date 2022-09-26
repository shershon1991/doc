#include <stdio.h>

//去掉字符串右边空格
/*int main()
{
	char s[100] = "hello world     ";

	//s[11] = 'a';
	//s[12] = 'b';
	//s[2] = '\n';
	int len = 0;
	while (s[len++]);
	len--;

	int i = 0;
	for (i = len-1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			s[i + 1] = 0;
			break;
		}
	}

	printf("(%s)\n", s);
	return 0;
}*/

//去掉字符串左边空格
int main()
{
          char s[100] = "  he  llo";

          int len = 0;
          while (s[len++] == ' ')
                    ;
          len--; //得到字符串前面的空格数

          int i = len;
          while (s[i])
          {
                    s[i - len] = s[i];
                    i++;
          }
          s[i - len] = 0; //讲字符串最后补0

          printf("(%s)\n", s);
          return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(const char *s)
{
	printf("%s\n", s);
}

int test1(char *s)
{
	*s = 'a';//s[0] = 'a';
	s++;
	*s = 'b';//s[1] = 'b';
	//memset(s, 0, strlen(s));
}

int main1(void)
{
	test("hello world\n");

	char s[] = "hello world";
	test1(s);
	printf("s = %s\n", s);
	return 0;
}

int main2(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	getchar();
	return 0;
}

int main()
{
	int a = 112;
	printf("%o", a);
}
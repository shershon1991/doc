#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100] = "cccc";
	char s2[100] = "dddd";
	printf("%d\n", strcmp(s1, s2));
	return 0;
}
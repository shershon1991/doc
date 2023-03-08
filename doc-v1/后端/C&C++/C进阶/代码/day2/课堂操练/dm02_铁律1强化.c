#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main21()
{
	char buf[128] = "abcdefg124456567";
	int i;
	int j = 0;

	char* p2 = NULL;
	char* p1 = NULL;

	p1 = &buf[0];
	p1 = &buf[1];
	p1 = &buf[2];

	for (i = 0; i < 10; i++)
	{
		p1 = &buf[i];
		printf("%c", *p1);
	}

	p2 = (char*)malloc(100);
	strcpy(p2, "abcdefg124456567");

	for (i = 0; i < 10; i++)
	{
		p1 = p2 + i; 
		printf("%c", *p1);
	}

	printf("hello...\n");
	system("pause");
	return;
}
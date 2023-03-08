#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char** getMem61(int num)
{
	char** p2;
	int i = 0;

	p2 = (char**)malloc(sizeof(char*) * num);
	if (p2 == NULL)
	{
		return NULL;
	}
	for (i = 0; i < num; i++)
	{
		p2[i] = (char*)malloc(sizeof(char) * 100);//char buf[100]
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	return p2;
}

int getMem62(char ***p3, int num)
{
	char** tmp = NULL;
	int i = 0;

	if (p3 == NULL)
	{
		return -1;
	}

	tmp = (char**)malloc(sizeof(char*) * num);
	if (tmp == NULL)
	{
		return NULL;
	}
	for (i = 0; i < num; i++)
	{
		tmp[i] = (char*)malloc(sizeof(char) * 100);//char buf[100]
		sprintf(tmp[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	*p3 = tmp;

	return 0;
}

void getMemFree62(char*** p3, int num)
{
	int i = 0;
	char** tmp = NULL;

	if (p3 = NULL)
	{
		return;
	}
	tmp = *p3;

	for (i = 0; i < num; i++)
	{
		free(tmp[i]);
	}
	free(tmp);

	*p3 = NULL;
}

void main61()
{
	int i, j = 0;
	char** p2 = NULL;
	int num = 5;
	char* tmp;
	char tmpBuf[100];

	//p2 = getMem61(num);
	getMem62(&p2,num);

	for (i = 0; i < num; i++)
	{
		printf("%s \n",p2[i]);
	}

	getMemFree62(&p2,num);

	system("pause");
	return;
}

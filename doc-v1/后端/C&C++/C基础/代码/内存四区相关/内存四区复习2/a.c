#include <stdio.h>

static int mymax = 100;

int *get_mymax()
{
	return &mymax;
}

void print_mymax()
{
	printf("mymax = %d\n", mymax);
}
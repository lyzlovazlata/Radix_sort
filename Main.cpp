#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions.h"


int main()
{
	srand(time(NULL));

	int arr[10];
	gen(arr, 10);
	printf("Initial Array:   ");
	print(arr, 10);

	printf("\n\n");

	radix_sort(arr, 10);
	printf("Final Array:   ");
	print(arr, 10);

	printf("\n\n");
}
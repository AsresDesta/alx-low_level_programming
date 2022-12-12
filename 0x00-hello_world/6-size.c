#include <stdio.h>
/**
 * main - print out sizes of data types in c
 * Return: 0
 */

int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;

	printf("size of a char: %lu bytes(s)\n", sizeof(char));
	printf("size of an int: %lu bytes(s)\n", sizeof(int));
	printf("size of a long int: %lu bytes(s)\n", sizeof(long int));
	printf("size of a long long int: %lu bytes(s)\n", sizeof(long long int));
	printf("size of a float: %lu bytes(s)\n", sizeof(float));
	return (0);


}

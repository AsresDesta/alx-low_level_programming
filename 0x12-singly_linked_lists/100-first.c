#include <stdio.h>

void __attribute__((constructor)) hare(void);

/**
 * hare - prints a string before the main finction is executed
 */
void hare(void)
{
	printf("you're beat! and must allow," "\nI bore my house upon my back!\n");
}


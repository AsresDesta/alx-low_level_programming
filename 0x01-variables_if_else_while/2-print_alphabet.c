#include <stdio.h>
/**
 * main - return alphabets
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}

#include "main.h"
#include <stdio.h>
/**
 * Print_number - prints int with putchar
 * @n: takes number , hello
 *
 * Return: void
 */

void Print_number(int n)
{
	unsigned int m;

	if (n < 0)
	{
		_putchar('-');
		m = -n;
	}
	else
	{
		m = n;
	}
	if (m / 10 != 0)
		print_number(m / 10);
	_putchar((m % 10) + '0');
}

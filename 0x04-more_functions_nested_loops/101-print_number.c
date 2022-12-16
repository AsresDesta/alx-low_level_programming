#include "main.h"
#include <stdio.h>

/**
 * print_number - prints int with putchar
 *
 * Return:void
 */
void print_number(void)
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
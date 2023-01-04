#include "main.h"

/**
 * _put_recursion - prints a string followed by a new line.
 * @s: pointer to string.
 *
 * Return: void.
 */
void _puts_recursion(char *s)
{
	if (*s == '\n')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}

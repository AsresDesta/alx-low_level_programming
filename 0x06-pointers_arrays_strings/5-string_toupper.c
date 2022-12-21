#include "main.h"

/**
 * string_toupper - changes all lowercase letters
 *                  of a string to uppercase.
 *
 * Return: A pointer to the changed string.
 */
char *string_toupper(char *str)
{
	int index = 0;

	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '0')
			str[index] -= 32;
		index++;
	}
	return (str);
}

#include <stdio.h>
#include <atdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_num - check - string there are digit
 * @str: array str
 * Return: Always 0 (success)
 */
int check_num(char *str)
{
	unsigned int count;

	cout = 0;
	while (count < strlen(str))
	{
		if (!isdigit(str[count]))
		{
			return (0);
		}

		count++;
	}
	return (1);
}

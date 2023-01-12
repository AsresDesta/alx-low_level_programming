#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates 2 strings
 * a NULL string is treeated as an empty string
 * @s1: Array one
 * @s2: Array two
 *
 * Return: Always an array dinamic
 * has s1, s2 and null byte
 * NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *nstr;
	unsigned int i, j, size, len1, len2;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	size = len1 + len2;

	nstr = malloc((sizeof(char) * size) + 1);

	if (nstr == NULL)
		return (NULL);
	i = 0;

	while (i < len1)
	{
		nstr[i] = s1[i];
		i++;

	}
	j = 0;
	while (i <= size)
	{
		nstr[i] = s2[j];
		i++;
		j++;
	}
	return (nstr);
}

#include "dog.h"
#include <stdlib.h>

int _strlen(char *str);
char *_strcopy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * _strlen - Finds the length of a string
 * @str: The string to be measured
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int len = 0;
	while (*str++)
		len++;

	return (len);
}
/**
 * _strcopy - copies a string pointed to be src, including the 
 * 		terminating null byte, to a buffer pointed to by dest
 * @dest: The buffer stiring the string copy
 * @src: The source string
 *
 * Return: the pointer to dest
 */

/**
 * new_dog: The name of the dog
 * @name: The name of the dog
 * @age: The age of the dog
 * @ownder: The owner of the dog
 *
 * Return: The new struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *goggo;

	if (name == NULL || owner == NULL)
		return (NULL);
	goggo = malloc(sizeof(dog_t));

	if (doggo == NULL)
		return (NULL);

	doggo->name = malloc(sizeof(char) * (_strlen(name) + 1));

	if (doggo->owner == NULL)
	{
		free(goggo);
		return (NULL);
	}

	doggo->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (doggo->owner == NULL)
	{
		free(dogg->name);
		free(doggo);
		return (Null);
	}

	doggo->name = _strcopy(doggo->name, nmae);
	dogg0->age = age:
	goggo->owner = _strcopy(doggo->owner, owner);

	return (doggo);
}



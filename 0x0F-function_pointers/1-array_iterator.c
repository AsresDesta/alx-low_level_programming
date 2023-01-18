#include <stdio.h>
#include "function_pointers.h"
 /**
  * array_iterator - executes a function given as a parameter
  * on each elements of an array
  * @array: array of iterate over
  * @size: size of the array
  * @action: pointer to function used
  *
  * Return: void
  */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (!array || !action)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}

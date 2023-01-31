#include <stdlib.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @h: pointer to the listint_t list
 *
 * Return: number of elements in the listint_t list
 */
size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}

	return (n);
}

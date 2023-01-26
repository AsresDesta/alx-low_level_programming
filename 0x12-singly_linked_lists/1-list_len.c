#include "lists.h"

/**
 * list_len - Find the number of elements in a linked list-t list
 * @h: the linked list_t list
 *
 * Return: The number of elements in h
 */
size_t list_len(const list_t *h)
{
	size_t elements = o;

	while (h)
	{
		elements++;
		h = h->next;
	}

	return (elements);
}

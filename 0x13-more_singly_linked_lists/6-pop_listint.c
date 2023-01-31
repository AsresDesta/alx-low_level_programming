#include "lists.h"

/**
 * pop_listint - Delets the head node of a listint_t list.
 * @head: A pointer to the addres of the head of the listint_t list
 *
 * Return: If the linked list is empty - 0. otherwise head node data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int ret;

	if (*head == NULL)
		return (0);

	tmp = *head;
	ret = (*head)->n;
	*head = (*head)->next;

	free(tmp);

	return (ret);
}


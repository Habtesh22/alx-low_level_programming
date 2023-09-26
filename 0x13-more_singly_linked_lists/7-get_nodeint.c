#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to head of list.
 * @index: Index of node to return, starting from 0.
 * Return: Pointer to indexed node or NULL if node doesn't exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current;

	if (head == NULL)
		return (NULL);
	current = head;
	for (i = 0; i < index && current != NULL; i++)
	{
		current = current->next;
	}

	if (i == index)
		return (current);
	return (NULL);
}

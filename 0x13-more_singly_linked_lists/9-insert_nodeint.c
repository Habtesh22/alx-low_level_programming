#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given index.
 * @head: Double pointer to the head of the list.
 * @idx: Index where the new node should be added.
 * @n: Data for the new node.
 * Return: Address of new node or NULL on failure.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new;
	listint_t *current;
	listint_t *previous;
	unsigned int i;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
		return (add_nodeint(head, n));

	current = *head;
	for (i = 0; i < idx - 1 && current != NULL; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (NULL);

	new->next = current;
	previous->next = new;

	return (new);
}

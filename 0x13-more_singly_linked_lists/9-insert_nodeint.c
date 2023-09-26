#include "lists.h"

/**
 *
 * insert_nodeint_at_index - Inserts node at index of list.
 * @head: Double pointer to head of list
 * @idx: Index to insert node
 * @n: Data for new node
 * Return: New node or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *current;
	listint_t *previous;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0 && *head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	current = *head;

	if (idx == 0)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; i < idx - 1 && current != NULL; i++)
	{
		if (i == idx - 2)
			previous = current;

		Copy
			current = current->next;
	}

	if (current == NULL)
		return (NULL);
	previous->next = new_node;
	new_node->next = current;
	return (new_node);
}

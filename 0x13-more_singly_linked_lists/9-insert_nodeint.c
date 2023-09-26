#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given index.
 * @head: Double pointer to head of list
 * @idx: Index to insert node
 * @n: Data for new node
 * Return: Address of new node or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *current;
	listint_t *previous;
	unsigned int i;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	for (i = 0; i < idx - 1 && current != NULL; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (NULL);

	previous->next = new_node;
	new_node->next = current;

	return (new_node);
}

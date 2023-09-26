#include "lists.h"

/**
 * free_listint_safe - Frees a list and sets head to NULL
 * @h: Double pointer to head of list
 * Return: Size of list freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes;
	listint_t *current;
	listint_t *tmp;
	listint_t *targets[64];

	int index = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	nodes = 0;

	while (index >= 0 && current != NULL)
	{
		tmp = current->next;
		if (current->next != NULL)
		{
			targets[index++] = current;
		}
		else
		{
			targets[index--] = NULL;
		}
		free(current);
		current = tmp;
		nodes++;
	}

	if (index > 0)
	{
		printf("There was a loop in the list.\n");
	}

	*h = NULL;

	return (nodes);
}

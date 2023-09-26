#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely
 * @head: Pointer to head of list
 * Return: Number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes;
	listint_t *current;
	listint_t *targets[64];
	int index = 0;

	current = (listint_t *) head;
	nodes = 0;

	if (current == NULL)
		return (0);

	while (index >= 0 && current != NULL)
	{
		if (current->next != NULL)
		{
			targets[index++] = current;
		}
		else
		{
			targets[index--] = NULL;
		}

		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		nodes++;
	}

	if (index >= 0)
	{
		printf("LOOP DETECTED\n");
		exit(98);
	}

	return (nodes);
}

#include "lists.h"

/**
 * print_listint_safe - Prints a list safely handling loops
 * @head: Pointer to head of list
 * Return: Number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	listint_t *current = (listint_t *)head;
	listint_t *prev_nodes[64];
	int index = 0;

	if (head == NULL)
		return (0);

	while (current != NULL)
	{
		if (index > 0 && prev_nodes[index - 1] == current)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			printf(" [LOOP DETECTED]\n");
			exit(98);
		}

		prev_nodes[index++] = current;
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		nodes++;
	}

	return (nodes);
}

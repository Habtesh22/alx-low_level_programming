#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely handling loops
 * @head: Pointer to head of list
 * Return: Number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t n_nodes = 0;
	listint_t *current = (listint_t *) head;
	listint_t *prev = NULL;

	if (head == NULL)
		return (0);

	while (current)
	{
		if (prev == current->next)
		{
			printf("-> [%p] (%d)\n", (void *)current, current->n);
			printf("[LOOP DETECTED]\n");
			exit(98);
		}

		printf("[%p] %d\n", (void *)current, current->n);
		prev = current;
		current = current->next;
		n_nodes++;
	}

	return (n_nodes);
}

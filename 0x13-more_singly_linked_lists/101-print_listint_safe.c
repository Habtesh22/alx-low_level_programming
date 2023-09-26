#include "lists.h"
#include <stdio.h>

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
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

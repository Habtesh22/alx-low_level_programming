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
	size_t count = 0;
	listint_t *ptr1 = head;
	listint_t *ptr2 = head;

	if (head == NULL || head->next == NULL)
		return (0);

	do {
		ptr2 = ptr2->next;
	} while (ptr2 && ptr2->next);

	if (ptr2 == NULL)
		return (0);

	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		count++;
	}

	return (count);
}

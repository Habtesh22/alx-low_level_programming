#include "lists.h"

/**
 * sum_listint - Returns the sum of all the
 * data (n) of a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 * Return: Sum of all data (n), or 0 if list is empty.
 */
int sum_listint(listint_t *head)
{
	listint_t *current;
	int sum = 0;

	current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}

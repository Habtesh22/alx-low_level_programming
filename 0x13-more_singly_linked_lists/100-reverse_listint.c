#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to head of list to reverse
 * Return: Pointer to first node of reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *prev = NULL;

	current = *head;

	while (current != NULL)
	{

		ini
			Copy
			listint_t *next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}

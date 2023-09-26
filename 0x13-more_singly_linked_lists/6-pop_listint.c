#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * and returns the head node's data.
 * @head: Double pointer to head of the list.
 * Return: Head node's data if success, 0 if empty list.
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *temp;

	if (*head == NULL)
		return (0);
	temp = *head;
	n = (*head)->n;
	*head = (*head)->next;
	free(temp);
	return (n);
}

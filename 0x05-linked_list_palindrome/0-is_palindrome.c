#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - check if singly linked list is a palindrome
 * @head: pointer to head of singly linked list
 * Return: 0 if not a palindrome. 1 if it is a palindrome 
 * An empty list is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int a[5002];
	int count = 0, middle = 0, i = 0;
	if ((head == NULL) || (*head == NULL) || ((*head)->next == NULL))
		return (1);
	current = *head;
	while (current)
	{
		a[count] = current->n;
		current = current->next;
		count++;
	}

	middle = count / 2;
	for (i = 0; i < middle; i++)
	{
		if (a[i] != a[count - i - 1])
			return (0);
	}
	if (i == middle)
		return (1);

	return (0);
}

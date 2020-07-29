#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a number into a sorted singly-linked list
 * @head: pointer to head of list
 * @number: value to insert
 * Return: address of the new node or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head, *prev = NULL;
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	} else
	{ 
		while ((current != NULL) && ((current->n) < number))
		{
			prev = current;
			current = current->next;
		}

		if (prev == NULL)
		{ 
			new->next = *head;
			*head = new;
		} else if (current)
		{
			prev->next = new;
			new->next = current;
		} else
		{
			prev->next = new;
		}
	}
	return (new);
}

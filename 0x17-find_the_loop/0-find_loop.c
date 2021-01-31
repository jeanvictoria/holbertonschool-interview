#include "lists.h"

/**
 * find_listint_loop - finds loop in linked list
 *
 * @head: linked list to check
 *
 * Return: NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *frabbit, *sturtle;

	if (head == NULL)
		return (NULL);
	frabbit = sturtle = head;
	while (sturtle->next != NULL && sturtle->next->next != NULL)
	{
		frabbit = frabbit->next;
		sturtle = sturtle->next->next;
		if (frabbit == sturtle)
		{
			frabbit = head;
			while (frabbit != sturtle)
			{
				frabbit = frabbit->next;
				sturtle = sturtle->next;
			}
			return (sturtle);
		}

	}
	return (NULL);
}

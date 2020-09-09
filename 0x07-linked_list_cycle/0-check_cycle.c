#include "lists.h"

/**
 * check_cycle - finds the loop in a linked list
 * @list: pointer to head of list
 * Return: true or false
 */
int check_cycle(listint_t *list)
{
	listint_t *t = list, *h = list;

	if (!list)
		return (0);
	while (h->next && h->next->next)
	{
		t = t->next;
		h = h->next->next;
		if (t == h)
			return (1);
	}
	return (0);
}

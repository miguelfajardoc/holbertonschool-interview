#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - found if a linked list has a cycle in it.
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *rabbit;
	listint_t *tortoise;

	rabbit = list;
	tortoise = list;

	while (rabbit != NULL && tortoise != NULL)
	{
		tortoise = tortoise->next;
		if (rabbit->next != NULL)
			rabbit = rabbit->next->next;
		if (tortoise == rabbit)
			return (1);
	}
	return (0);
}

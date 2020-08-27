#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - evaluate if a single linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *aux;

	if (*head == NULL)
	{
		return (1);
	}
	aux = *head;
	if (recursion_is_palindrome(head, aux) == 2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * recursion_is_palindrome - evaluate if a single linked list is a palindrome
 * recursively
 * @head: pointer to head of list
 * @aux: pointer auxiliar that starts in the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int recursion_is_palindrome(listint_t **head, listint_t *aux)
{
	int result;

	if (aux->next != NULL)
	{
		result = recursion_is_palindrome(head, aux->next);
	}
	else
	{
		return (check_equal_value(*head, aux));
	}
	if (result == 0)
	{
		return (result);
	}
	else if (result == 2)
	{
		return (2);
	}
	else
	{
		/* printf("compare *head->next == aux: %p == %p\n", (void*)(*head)->next, (void*)aux); */
		/* printf("compare *head == aux: %p == %p\n", (void*)*head, (void*)aux); */
		if((*head)->next == aux || *head == aux)
		{
			return (2);
		}
		else
		{
			*head = (*head)->next;
			return (check_equal_value(*head, aux));
		}
	}
	/*return recursion_is_palindrome(head, aux);*/
}


/**
 * check_equal_value - evaluate if 2 nodes have the same value
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 * Return: 1 if there are equal, 0 otherwise
 */
int check_equal_value(listint_t *head, listint_t *aux)
{
	/* printf("comparing %d and %d in %p and %p \n", head->n, aux->n, (void*)head, (void*)aux); */
	if (head->n == aux->n)
		return (1);
	else
		return (0);
	return (0);
}

#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - check if a long unsigned int is a palindrome
 * @n: the number to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long long int big_zero = 1000000000000000000;
	int top = 0;
	int bot = 0;

	big_zero *= 10;
	while (big_zero != 1)
	{
		/* printf("top: %d\n", top); */
		/* printf("a: %lu\n", n); */
		/* printf("big_zero: %llu\n", big_zero); */
		/* printf("bot: %d\n", bot); */
		/* printf("///-----------------////\n"); */
		top = n / big_zero;
		if (top != 0)
		{
			n = n % big_zero;
			bot = n % 10;
			n = n / 10;
			if (top != bot)
				return (0);
			if (big_zero != 10)
				big_zero /= 10;
			big_zero /= 10;
		}
		else
		{
			big_zero /= 10;
		}
	}

	return (1);
}

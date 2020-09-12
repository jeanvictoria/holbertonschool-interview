#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given integer is a palindrome
 * @n: input integer
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned int reverse = 0;

	if (n && !(n % 10))
		return (0);
	for (; n > reverse; n /= 10)
		reverse = (reverse * 10) + n % 10;
	return (n == reverse || n == (reverse / 10));
}

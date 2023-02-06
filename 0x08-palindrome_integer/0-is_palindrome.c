#include "palindrome.h"


/**
 * is_palindrome - check if the n is a palindrome number
 * @n : number to check
 *
 * Return: 1 if yes, 0 if no
*/
int is_palindrome(unsigned long n)
{
	unsigned long reverse = 0, k = n;

	while (k != 0)
	{
		reverse = reverse * 10 + (k % 10);
		k /= 10;
	}

	if (n == reverse)
		return (1);
	return (0);
}

#include "holberton.h"

/**
 * _isdigit - Checks if a number is a digit
 * @c: number to check
 * Return: 1 if yes else 0
*/
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Calculates the length of a string
 * @s: string to calculate
 *
 * Return: the length of the string
*/
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;

	return (count);
}

/**
 * print - Displays a message with putchar
 * @string: string to display
*/
void print(char *string)
{
	while (*string)
		_putchar(*string++);
	_putchar('\n');
}

/**
 * multiply - multiply two numbers
 * @num1: first number
 * @num2: second number
 * @len1: length of the first number
 * @len2: length of the second number
*/
void multiply(char *num1, char *num2, int len1, int len2)
{
	int i, j, carry = 0, n1, n2, sum, index1 = 0, index2 = 0;
	char *result;

	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return;
	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		index2 = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + (result[index1 + index2] - '0') + carry;
			carry = sum / 10;
			result[index1 + index2] = sum % 10 + '0';
			index2++;
		}
		if (carry > 0)
			result[index1 + index2] += carry;
		index1++;
	}
	for (i = _strlen(result) - 1; i >= 0 && result[i] == '0'; i--)
	if (i == -1)
	{
		print("0");
		return;
	}
	while (i >= 0)
	{
		_putchar(result[i]);
		i--;
	}
	_putchar('\n');
	free(result);
}

/**
 * main - main entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 1 on success else 0
*/
int main(int argc, char *argv[])
{
	int i, len1, len2;
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3)
	{
		print("Error\n");
		exit(98);
	}

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	for (i = 0; num1[i] != '\0'; i++)
	{
		if (!_isdigit(num1[i]))
		{
			print("Error\n");
			exit(98);
		}
	}

	for (i = 0; num2[i] != '\0'; i++)
	{
		if (!_isdigit(num2[i]))
		{
			print("Error\n");
			exit(98);
		}
	}

	if (len1 == 0 || len2 == 0)
	{
		print("0");
		return (1);
	}

	multiply(num1, num2, len1, len2);
	return (1);
}

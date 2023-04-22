#include "main.h"
#include <stdio.h>
/**
 * print_integer - prints an integer
 * @n: integer to print
 *
 * Return: number of digits printed
 */
int print_integer(int n)
{
	int count = 0;

	if (n == 0)
		return (_putchar('0'));

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_integer(n / 10);

	count += _putchar(n % 10 + '0');

	return (count);
}

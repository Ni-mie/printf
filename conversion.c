#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @args: Arguments.
 * Return: 1.
 */
int print_binary(va_list args)
{
	int flag = 0;
	int cont = 0;
	int i, m = 1, n;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((m << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			n = p >> (31 - i);
			putchar(n + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		putchar('0');
	}
	return (cont);
}

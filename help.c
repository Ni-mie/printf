#include "main.h"
/**
 * print_hex_prefix - Prints a hex.
 * Return: 2.
 */
int print_hex_prefix(void)
{
	_putchar('0');
	_putchar('x');
	return (2);
}
/**
 * print_rot13 - ROT13
 * @args: Arguments
 * Return: count
 *
 */
int print_rot13(va_list args)
{
	int i, j, count = 0;
	int k = 0;
	char *str = va_arg(args, char*);
	char upper[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char lower[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		k = 0;
		for (j = 0; upper[j] && !k; j++)
		{
			if (str[i] == upper[j])
			{
				_putchar(lower[j]);
				count++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_rev - Function that prints a str in reverse
 * @args: Arguments
 *
 * Return: String
 */
int print_rev(va_list args)
{

	char *str = va_arg(args, char*);
	int i;
	int j = 0;

	if (str == NULL)
		str = "(null)";
	while (str[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(str[i]);
	return (j);
}

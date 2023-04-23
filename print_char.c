#include "main.h"

/**
 * print_char - Prints a char.
 * @args: Arguments.
 * Return: 1.
 */
int print_char(va_list args)
{
	char ch;

	ch = va_arg(args, int);
	_putchar(ch);
	return (1);
}

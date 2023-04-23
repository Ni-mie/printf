#include "main.h"

/**
 * printf_char - Prints a char.
 * @val: Arguments.
 * Return: 1.
 */
int print_char(va_list args)
{
	char ch;

	ch = va_arg(args, int);
	_putchar(ch);
	return (1);
}

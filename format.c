#include "main.h"

/**
 * print_char - Prints a char.
 * @args: Arguments.
 * Return: 1.
 */
int print_char(va_list list)
{
	char ch;

	ch = va_arg(args, int);
	putchar(ch);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: arguments
 * Return: return characters.
 */
int print_string(va_list args)
{
	char *str;
	int i, len;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
		len = strlen(str);
		for (i = 0; i < len; i++)
			putchar(str[i]);
		return (len);
	}
	else
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
			putchar(str[i]);
		return (len);
	}
}

/**
 * print_percent - Prints the character %.
 * Return: 1.
 */
int print_percent(void)
{
	putchar(37);
	return (1);
}

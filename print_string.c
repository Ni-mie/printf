#include "main.h"
/**
 * print_string - Print a string.
 * @args: Arguments.
 * Return: Length of string.
 */

int print_string(va_list args)
{
	char *str;
	int i, len;

	str = va_arg(val, char *);

	if (str == NULL)
	{
		str = "(null)";
		len = strlen(str);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
}
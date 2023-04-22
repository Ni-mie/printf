#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				printed += putchar(va_arg(args, int));
			case 'd':
			case 'i':
				printed += print_integer(va_arg(args, int));
				break;
			case '%':
				printed += putchar('%');
				break;
			default:
				printed += putchar('%');
				printed += putchar(*format);
				break;
			}
		}
		else
		{
			printed += putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (printed);
}

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
		return (putchar('0'));

	if (n < 0)
	{
		count += putchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_integer(n / 10);

	count += putchar(n % 10 + '0');

	return (count);
}
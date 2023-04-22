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
				printed += _putchar(va_arg(args, int));
			case 'd':
			case 'i':
				printed += print_integer(va_arg(args, int));
				break;
			case '%':
				printed += _putchar('%');
				break;
			default:
				printed += _putchar('%');
				printed += _putchar(*format);
				break;
			}
		}
		else
		{
			printed += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (printed);
}

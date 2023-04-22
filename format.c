#include "main.h"

/**
 * _printf - Main Function
 * @format: A string
 * Return: Always 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char c;

	va_start(args, format);

	while ((c = *format++) != '\0')
	{
		if (c != '%')
		{
			_putchar(c);
			printed_chars++;
			continue;
		}

		switch (*format++)
		{
		case 'c':
			_putchar(va_arg(args, int));
			printed_chars++;
			break;

		case 's':
			printed_chars += printf("%s", va_arg(args, char *));
			break;

		case '%':
			_putchar('%');
			printed_chars++;
			break;
		default:
			_putchar('%');
			_putchar(c);
			printed_chars += 2;
		}

	}

	va_end(args);
	return (printed_chars);
}

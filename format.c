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
			putchar(c);
			printed_chars++;
			continue;
		}
		switch (*format++)
		{
		case 'c':
			putchar(va_arg(args, int));
			printed_chars++;
			break;
		case 's':
			printed_chars += printf("%s", va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			printed += print_integer(va_arg(args, int));
			break;
		case '%':
			putchar('%');
			printed_chars++;
			break;
		default:
			putchar('%');
			putchar(c);
			printed_chars += 2;
		}
	}
	va_end(args);
	return (printed_chars);
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

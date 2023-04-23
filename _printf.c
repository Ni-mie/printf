#include "main.h"
/**
 * _printf - Print Function
 * @format: identifier to look for.
 * Return: the length
 */
int _printf(const char * const format, ...)
{

	int len = 0;
	const char *p = format;

	va_list args;

	va_start(args, format);

	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
			case 's':
				len += print_string(args);
				break;
			case 'c':
				len += print_char(args);
				break;
			case '%':
				len += print_percent();
				break;
			case 'i': case 'd':
				len += print_int(args);
				break;
			default:
				putchar('%');
				putchar(*p);
				len += 2;
				break;
			}
			p++;
		}
		else
		{
			putchar(*p++);
			len++;
		}
	}
	va_end(args);
	return (len);
}

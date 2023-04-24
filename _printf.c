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
			case 'b':
				len += print_binary(args);
				break;
			case 'u':
				len += print_unsigned_int(args);
				break;
			case 'o':
				len += print_octal(args);
				break;
			case 'x':
				if (*(p+1) == '#')
				{
					len += print_hex_prefix();
					p++;
				}
				len += print_hex(args);
				break;
			case 'X':
				if (*(p+1) == '#')
				{
					len += print_hex_prefix();
					p++;
				}
				len += print_HEX(args);
				break;
			case 'S':
				len += print_exclusive(args);
				break;
			case 'p':
				len += print_pointer(args);
				break;
			default:
				_putchar('%');
				 if (*p == '+')
				 {
					 _putchar('+');
					 len++;
				 }
				 else if (*p == ' ')
				 {
					 _putchar(' ');
					 len++;
				 }
				_putchar(*p);
				len += 2;
				break;
			}
			p++;
		}
		else
		{
			_putchar(*p++);
			len++;
		}
	}
	va_end(args);
	return (len);
}

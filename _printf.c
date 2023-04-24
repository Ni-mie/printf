#include "main.h"
/**
 * _printf - Print Function
 * @format: identifier to look for.
 * Return: the length
 */
int _printf(const char * const format, ...)
{

	unsigned int len = 0;
	const char *p = format;

	char buf[1024];
	size_t bufsize = sizeof(buf);

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
				len += print_string(args, buf + len,
						    bufsize - len);
				break;
			case 'c':
				len += print_char(args, buf + len,
						  bufsize - len);
				break;
			case '%':
				len += print_percent(buf + len,
						     bufsize - len);
				break;
			case 'i': case 'd':
				len += print_int(args, buf + len,
						 bufsize - len);
				break;
			case 'b':
				len += print_binary(args, buf + len,
						    bufsize - len);
				break;
			case 'u':
				len += print_unsigned_int(args, buf + len,
							  bufsize - len);
				break;
			case 'o':
				len += print_octal(args, buf + len,
						   bufsize - len);
				break;
			case 'x':
				len += print_hex(args, buf + len,
						 bufsize - len);
				break;
			case 'X':
				len += print_HEX(args, buf + len,
						 bufsize - len);
				break;
			case 'S':
				len += print_exclusive(args, buf + len,
					bufsize - len);
				break;
			case 'p':
				len += print_pointer(args, buf + len,
					bufsize - len);
				break;
			case 'r':
				len += print_rev(args, buf + len,
					bufsize - len);
				break;
			default:
				buf[len++] = '%';
				buf[len++] = *p;
				break;
			}
			p++;
		}
		else
			buf[len++] = *p++;
		if (len >= bufsize)
		{
			write(STDOUT_FILENO, buf, len);
			len = 0;
		}
	}
	va_end(args);

	if (len > 0)
	{
		write(STDOUT_FILENO, buf, len);
	}

	return (len);
}

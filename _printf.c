#include "main.h"
/**
 * _printf - Print Function
 * @format: identifier to look for.
 * Return: the le
 */
int _printf(const char * const format, ...)
{
	convert n[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_percent},
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i]
			    && m[j].id[1] == format[i + 1])
			{
				len += n[j].f(args);
				i = i + 2;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}

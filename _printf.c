#include "main.h"

/**
 * _printf - Print Function
 * @format: identifier to look for.
 * Return: the length
 */
int _printf(const char * const format, ...)
{
	convert t[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_percent},
	};
	va_list args;
	int i = 0, j, len = 0, found_match = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		found_match = 0;

		for (j = 0; j < 3; j++)
		{
			if (strcmp(t[j].id, &format[i]) == 0)
			{
				len += t[j].f(args);
				i += strlen(t[j].id);
				found_match = i;
				break;
			}
		}

		if (!found_match)
		{
			putchar(format[i]);
			len++;
			i++;
		}
	}

	va_end(args);
	return (len);
}

#include "main.h"
/**
 * _printf - Print Function
 * @format: identifier to look for.
 * Return: the le
 */
int _printf(const char * const format, ...)
{
	int printed_chars;
	convert_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, args);
	va_end(args);
	return (printed_chars);
}

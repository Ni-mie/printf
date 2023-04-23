#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
 * struct format - conversion specifiers for printf
 * @id: type char pointer
 * @f: pointer
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert;

int print_binary(va_list args);
int print_int(va_list args);
int print_dec(va_list args);
int print_percent(void);
int print_string(va_list args);
int print_char(va_list args);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
int print_hex_prefix(void);
int printf_HEX_2(unsigned int num);
char *rev_string(char *);
int print_rev(va_list args);
int print_pointer(va_list args);
int print_hex_2(unsigned long int num);
int print_exclusive(va_list args);
int print_HEX(va_list args);
int print_hex(va_list args);
int print_octal(va_list args);
int print_unsigned_int(va_list args);
int print_binary(va_list args);
int print_int(va_list args);
int print_dec(va_list args);
int print_percent(void);
int print_string(va_list args);
int print_char(va_list args);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

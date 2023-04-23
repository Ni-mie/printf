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
int print_HEX_aux(unsigned int num);
int print_exclusive(va_list args, char *buf, size_t bufsize);
int print_HEX(va_list args, char *buf, size_t bufsize);
int print_hex(va_list args, char *buf, size_t bufsize);
int print_octal(va_list args, char *buf, size_t bufsize);
int print_unsigned_int(va_list args, char *buf, size_t bufsize);
int print_binary(va_list args, char *buf, size_t bufsize);
int print_int(va_list args, char *buf, size_t bufsize);
int print_dec(va_list args);
int print_percent(char *buf, size_t bufsize);
int print_string(va_list args, char *buf, size_t bufsize);
int print_char(va_list args, char *buf, size_t bufsize);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

#ifndef MAIN_H
#define MAIN_H

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define UNUSED(x) void(x)
#define BUFF_SIZE 1024

/* FLAGS */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define S_LONG 2
#define S_SHORT 1
/**
 * struct format - conversion specifiers for printf
 * @id: type char pointer
 * @f: pointer
 *
 */

typedef struct format
{
	char *id;
	int (*fn)(var_list, char[], int, int, int, int);
} convert;
int print_rev(va_list args);
int print_rot13( va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_hex_prefix(void);
int printf_HEX_2(unsigned int num);
char *rev_string(char *);
int print_rev(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_pointer(va_list args);
int print_hex_2(unsigned long int num);
int print_exclusive(va_list args);
int print_HEX(va_list args);
int print_hex(va_list args);
int print_octal(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_unsigned_int(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_dec(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
                int flags, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[],
                int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
                int flags, int width, int precision, int size);

int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);



int _putchar(char c);
int _printf(const char *format, ...);


#endif

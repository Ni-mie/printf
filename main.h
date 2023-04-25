#ifndef MAIN_H
#define MAIN_H

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

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
int print_rev(va_list args);
int print_rot13( va_list args);
int print_hex_prefix(void);
int printf_HEX_2(unsigned int num);
char *rev_string(char *);
int print_rev(va_list args);
int print_pointer(va_list args, ...);
int print_hex_2(unsigned long int num);
int print_exclusive(va_list args);
int print_HEX(va_list args, ...);
int print_hex(va_list args, ...);
int print_octal(va_list args, ...);
int print_unsigned_int(va_list args, ...);
int print_binary(va_list args);
int print_int(va_list args, ...);
int print_dec(va_list args);
int print_percent(va_list args, ...);
int print_string(va_list args, ...);
int print_char(va_list args, ...);
int _putchar(char c);
int _printf(const char *format, ...);


int get_width(const char *format, int *i, va_list);
/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


#endif

#define BUFFER_SIZE 1024
#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @args: Arguments.
 * Return: 1.
 */
int print_binary(va_list args)
{
	 int flag = 0;
	int count = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}
/**
 * print_unsigned_int - Prints unsigned integer
 * @args: Argument.
 * Return: Characters
 */
int print_unsigned_int(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	char buffer[BUFFER_SIZE];
	int i = BUFFER_SIZE - 1, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}

	while (++i < BUFFER_SIZE)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}

/**
 * print_octal - Prints an unsigned octal number.
 * @args: Arguments.
 * Return: Count.
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[BUFFER_SIZE];
	int i = BUFFER_SIZE - 1, count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (buffer[i + 1] != '0')
	{
		_putchar(buffer[++i]);
		count++;
	}

	while (++i < BUFFER_SIZE)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}
/**
 * print_hex - Prints an hexgecimal number (lowercase).
 * @args: Arguments.
 * Return: Count.
 */
int print_hex(va_list args)
{unsigned int n = va_arg(args, unsigned int);
	char buffer[BUFFER_SIZE];
	int i = BUFFER_SIZE - 1, count = 0;
	char c;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		c = n % 16;
		buffer[i--] = (c < 10) ? (c + '0') : (c - 10 + 'a');
		n /= 16;
	}

	while (++i < BUFFER_SIZE)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}
/**
 * print_HEX - Prints an hexdecimal number (Upper Case).
 * @args: Arguments.
 * Return: Counter.
 */
int print_HEX(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[BUFFER_SIZE];
	int i = BUFFER_SIZE - 1, count = 0;
	char c;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		c = n % 16;
		buffer[i--] = (c < 10) ? (c + '0') : (c - 10 + 'A');
		n /= 16;
	}

	while (++i < BUFFER_SIZE)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}

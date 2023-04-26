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
int print_unsigned_int(va_list args, ...)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
/**
 * print_octal - Prints an unsigned octal number.
 * @args: Arguments.
 * Return: Count.
 */
int print_octal(va_list args, ...)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 8;
		temp /= 8;
	}
	if (num != 0)
	{
		_putchar('0');
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count + (num != 0 ? 1 : 0));
}
/**
 * print_hex - Prints an hexgecimal number (lowercase).
 * @args: Arguments.
 * Return: Count.
 */
int print_hex(va_list args, ...)
{
	int i;
	int flag = 0;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (temp / 16 != 0)
	{
		temp /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = num % 16;
		num /= 16;
	}
	if (flag == '#')
	{
		_putchar('0');
		_putchar('x');
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count + (flag == '#' ? 2 : 0));
}
/**
 * print_HEX - Prints an hexdecimal number (Upper Case).
 * @args: Arguments.
 * Return: Counter.
 */
int print_HEX(va_list args, ...)
{

	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (temp / 16 != 0)
	{
		temp /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = num % 16;
		num /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

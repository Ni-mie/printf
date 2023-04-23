#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @args: Arguments.
 * Return: 1.
 */
int print_binary(va_list args)
{
	int flag = 0;
	int cont = 0;
	int i, m = 1, n;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((m << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			n = p >> (31 - i);
			putchar(n + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		putchar('0');
	}
	return (cont);
}
/**
 * print_unsigned_int - Prints unsigned integer
 * @args: Arguments
 * Return: Characters
 */
int print_unsigned_int(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last_digit = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last_digit < 0)
	{
		putchar('-');
		num = -num;
		n = -n;
		last_digit = -last_digit;
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
			putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	putchar(last_digit + '0');

	return (i);
}
/**
 * print_octal - Prints an unsigned octal number.
 * @args: Arguments.
 * Return: Count.
 */
int print_octal(va_list args)
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
	for (i = count - 1; i >= 0; i--)
	{
		putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
/**
 * print_hex - Prints an hexgecimal number (lowercase).
 * @args: Arguments.
 * Return: Count.
 */
int print_hex(va_list args)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
/**
 * print_HEX - Prints an hexdecimal number (Upper Case).
 * @args: Arguments.
 * Return: Counter.
 */
int print_HEX(va_list args)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;
		putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

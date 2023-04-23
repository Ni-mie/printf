#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @args: Arguments.
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: 1.
 */
int print_binary(va_list args, char *buf, size_t bufsize)
{
	 char binary[33] = {'\0'};

	 int leading_zeros = 1, index = 31;

	 unsigned int num = va_arg(args, unsigned int);

	while (num > 0 && index >= 0)
	{
		binary[index--] = (num & 1) + '0';
		num >>= 1;
		leading_zeros = 0;
	}
	if (leading_zeros)
		return snprintf(buf, bufsize, "0");
	else
		return snprintf(buf, bufsize, "%s", binary + index + 1);
}
/**
 * print_unsigned_int - Prints unsigned integer
 * @args: Arguments
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: Characters
 */
int print_unsigned_int(va_list args, char *buf, size_t bufsize)
{
	unsigned int n = va_arg(args, unsigned int);

	int num, last_digit = n % 10, digit, exp = 1;
	int  i = 1;

	return (snprintf(buf, bufsize, "%u", n));
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
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: Count.
 */
int print_octal(va_list args, char *buf, size_t bufsize)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	unsigned int temp = num;

	return (snprintf(buf, bufsize, "%o", num));

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
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: Count.
 */
int print_hex(va_list args, char *buf, size_t bufsize)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	unsigned int temp = num;

	return (snprintf(buf, bufsize, "%x", num));

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
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: Counter.
 */
int print_HEX(va_list args, char *buf, size_t bufsize)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	unsigned int temp = num;

	return (snprintf(buf, bufsize, "%X", num));

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

#include "main.h"

/**
 * print_pointer - Prints an pointer.
 * @args: Arguments.
 * Return: Count
 */
int print_pointer(va_list args)
{
	void *p;
	char *s = "(nil)";
	unsigned long int a;
	int b;
	int i;

	p = va_arg(args, void*);


	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = print_hex_2(a);
	return (b + 2);
}
/**
 * print_hex_2 - Prints a hexdecimal number (lowercase).
 * @num: Arguments.
 * Return: count.
 */
int print_hex_2(unsigned long int num)
{
	long int i;
	long int *arr;
	long int count = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(long int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

/**
 * printf_HEX_2 - Prints an hexdecimal number (Uppercase).
 * @num: number to print.
 * Return: counter.
 */
int printf_HEX_2(unsigned int num)
{
	int i;
	int *arr;
	int count = 0;
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
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

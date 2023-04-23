#include "main.h"

/**
 * print_HEX_aux - Prints an hexdecimal number (uppercase).
 * @num: Number.
 * Return: count.
 */
int print_HEX_aux(unsigned int num)
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
		putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

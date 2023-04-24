#include "main.h"

/**
 * print_pointer - Prints an pointer.
 * @args: Arguments.
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: Count
 */
int print_pointer(va_list args, char *buf, size_t bufsize)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int b;
	int i;

	p = va_arg(args, void*);

	return (snprintf(buf, bufsize, "%p", p));

	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	putchar('0');
	putchar('x');
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
		putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
/**
 * print_rev - Function that reverses a string
 * @args: Arguments
 * Return: the string
 */
int print_rev(va_list args)
{
	int len;

	char *str = va_arg(args, char*);
	char *ptr;

	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		putchar(ptr[len]);
	free(ptr);
	return (len);
}
/**
 * rev_string - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

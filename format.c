#include "main.h"

/**
 * print_char - Prints a char.
 * @args: Arguments.
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: 1.
 */
int print_char(va_list args, char *buf, size_t bufsize)
{
	char ch;

	ch = va_arg(args, int);

	return (snprintf(buf, bufsize, "%c", ch));
	putchar(ch);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: arguments
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: return characters.
 */
int print_string(va_list args, char *buf, size_t bufsize)
{
	char *str;
	int i, len;

	str = va_arg(args, char *);

	return (snprintf(buf, bufsize, "%s", str));

	if (str == NULL)
	{
		str = "(null)";
		len = strlen(str);
		for (i = 0; i < len; i++)
			putchar(str[i]);
		return (len);
	}
	else
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
			putchar(str[i]);
		return (len);
	}
}

/**
 * print_percent - Prints the character %.
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: 1.
 */
int print_percent(char *buf, size_t bufsize)
{
	return (snprintf(buf, bufsize, "%%"));
	putchar(37);
	return (1);
}
/**
 * print_int - prints integer
 * @args: argument to print
 * @buf: Buffer
 * @bufsize: Buffer Size
 * Return: number of characters printed
 */
int print_int(va_list args, char *buf, size_t bufsize)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	return (snprintf(buf, bufsize, "%d", n));

	n = n / 10;
	num = n;

	if (last < 0)
	{
		putchar('-');
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
			putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	putchar(last + '0');

	return (i);
}
/**
 * print_dec - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */

int print_dec(va_list args)
{
	int n = va_arg(args, int);
	int num, last_digit = n % 10, digit;
	int  i = 1;
	int exp = 1;

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

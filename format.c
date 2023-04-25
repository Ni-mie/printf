#define BUFFER_SIZE 1024
#include "main.h"
/**
 * print_char - Prints a char.
 * @args: Arguments.
 * Return: 1.
 */
int print_char(va_list args, ...)
{
	char ch;

	ch = va_arg(args, int);

	_putchar(ch);
	return (1);
}

/**
 * print_string - Prints a string.
 * @args: arguments
 * Return: return characters.
 */
int print_string(va_list args, ...)
{
	char *str;
	int i, len;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
		len = strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
	else
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
}

/**
 * print_percent - Prints the character %.
 * @args: Arguments.
 * Return: 1.
 */
int print_percent(va_list args, ...)
{
	(void) args;
	_putchar(37);
	return (1);
}
/**
 * print_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int print_int(va_list args, ...)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1, show_sign = 0,
	space_padding = 0;
	int  i = 1, count = 0;

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
	if (show_sign && n >= 0)
	{
		_putchar('+');
		count++;
	}
	else if (!show_sign && space_padding && n >= 0)
	{
		_putchar(' ');
		count++;
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
 * print_exclusive - Print exclusives string.
 * @args: Argument.
 * Return: Length of the string.
 */
int print_exclusive(va_list args)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + printf_HEX_2(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}

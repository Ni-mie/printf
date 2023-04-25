#include "main.h"
/**
 * _printf - Print Function
 * @format: identifier to look for.
 * Return: the length
 */
int _printf(const char * const format, ...)
{

	int len = 0;
	const char *p = format;

	va_list args;

	va_start(args, format);

	while (*p != '\0')
	{
		if (*p == '%')
		{
			int show_sign = 0;
			int left_justify = 0;
			int space_padding = 0;
			int zero_padding = 0;
			int alternate_form = 0;
			int fw = 0;
			int precision = -1;
			int length_modifier = 0;

			p++;

			while (*p == '+' || *p == ' ' || *p == '#'
				|| *p == '-' || *p == '0')
			{
				if (*p == '+')
					show_sign = 1;
				else if (*p == ' ')
					space_padding = 1;
				else if (*p == '0')
					zero_padding = 1;
				else if (*p == '-')
					left_justify = 1;
				else if (*p == '#')
					alternate_form = 1;

				p++;
			}

			if (*p >= '1' && *p <= '9')
			{
				fw = 0;

				while (*p >= '0' && *p <= '9')
				{
					fw = fw * 10 + (*p - '0');
					p++;
				}
			}

			if (*p == '.')
			{
				p++;

				if (*p >= '0' && *p <= '9')
				{
					precision = 0;

					while (*p >= '0' && *p <= '9')
					{
						precision =
							precision * 10 +
							(*p - '0');
						p++;
					}
				}
				else if (*p == '*')
				{
					precision = va_arg(args, int);
					p++;
				}
				else
				{
					precision = 0;
				}
			}

			if (*p == 'h' || *p == 'l')
			{
				length_modifier = *p;
				p++;
			}
			switch (*p)
			{
			case 's':
				len += print_string(args, show_sign,
						    space_padding,
						    alternate_form,
						    zero_padding,
						    left_justify, fw,
						    precision);
				break;
			case 'c':
				len += print_char(args,show_sign,
						  zero_padding,
						  space_padding,
						  alternate_form,
						  left_justify, fw,
						  precision);
				break;
			case '%':
				len += print_percent(args, left_justify, fw);
				break;
			case 'i': case 'd':
				len += print_int(args,show_sign,
						 zero_padding,
						 left_justify,
						 space_padding,
						 alternate_form,
						 left_justify, fw,
						 precision, length_modifier);
				break;
			case 'b':
				len += print_binary(args);
				break;
			case 'u':
				len += print_unsigned_int(args,
							  show_sign,
							  alternate_form,
							  left_justify, fw,
							  precision,
							  zero_padding,
							  space_padding,
							  precision,
							  length_modifier);
				break;
			case 'o':
				len += print_octal(args,
						   left_justify,
						   fw, precision,
						   zero_padding,
						   show_sign,
						   space_padding,
						   alternate_form,
						   length_modifier);
				break;
			case 'x':
				len += print_hex(args,
						 left_justify,
						 fw, precision,
						 space_padding, show_sign,
						 zero_padding,
						 alternate_form, 0,
						 length_modifier);
				break;
			case 'X':
				len += print_HEX(args,
						 left_justify,
						 fw, precision,space_padding,
						 show_sign,
						 zero_padding,
						 alternate_form, 1,
						 length_modifier);
				break;
			case 'S':
				len += print_exclusive(args);
				break;
			case 'p':
				len += print_pointer(args);
				break;
			case 'r':
				len += print_rev(args);
				break;
			case 'R':
				len += print_rot13(args);
				break;
			default:
				_putchar('%');
				_putchar(*p);
				len += 2;
				break;
			}
			p++;
		}
		else
		{
			_putchar(*p++);
			len++;
		}
	}
	va_end(args);
	return (len);
}

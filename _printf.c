#include "main.h"

/**
 * print_char - Prints a character
 * @args: A va_list containing the character to be printed
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: A va_list containing the string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
  
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;

	}

	return (i);
}

/**
 * print_percent - Prints a percent sign
 *
 * Return: The number of characters printed
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}

/**
 * print_int - Prints an integer
 * @args: A va_list containing the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	int i = 1;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	while (num / i > 9)
		i *= 10;

	while (i > 0)
	{
		_putchar('0' + (num / i));
		count++;
		num %= i;
		i /= 10;
	}

	return (count);
}

/**
 * _printf - Prints a formatted string
 * @format: A pointer to a string containing format specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += print_percent();
					break;
				case 'd':
				case 'i':
					count += print_int(args);
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

#include "main.h"
/**
 * print_char - print char arguments
 * @args: va_list argument
 * Return: return char number
 */
int print_char(va_list args)
{
	_putchar((char)va_arg(args, int));
	return (1);
}

/**
 * print_string - print string arguments
 * @args: va_list argument
 * Return: return the string
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_percent - print the percent argument
 * @args: va_list argument
 * Return: return the percent
 */
int print_percent(va_list args)
{
	(void) args;
	_putchar('%');
	return (1);
}

/**
 * print_int - print integer
 * @args: va_list argument
 * Return: returns integer
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int div = 1;
	int count = 0;
	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	while (n / div >= 10)
		div *= 10;
	while (div > 0)
	{
		_putchar((n / div) + '0');
		count++;
		n %= div;
		div /= 10;
	}
	return (count);
}

/**
 * _printf - produces output to a format
 * @format: character string argument
 * Return: returns an int value
 */
int _printf(const char *format, ...)
{
	int count;
	int i;
	va_list args;
	int (*print_func[5])(va_list);
	char specifiers[5];

	va_start(args, format);

	print_func[0] = print_char;
	print_func[1] = print_string;
	print_func[2] = print_percent;
	print_func[3] = print_int;
	print_func[4] = print_int;

	specifiers[0] = 'c';
	specifiers[1] = 's';
	specifiers[2] = '%';
	specifiers[3] = 'd';
	specifiers[4] = 'i';

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; i < 5; i++)
			{
				if (*format == specifiers[i])
				{
					count += functions[i](args);
					break;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

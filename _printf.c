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

	if (str == NULL)
		str = "(nil)";
	while (*str)
	{
		_putchar(*str);
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
	int count = 0;
	char buffer[11];
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	for (i--; i >= 0; i--)
	{
		_putchar(buffer[i]);
		count++;
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
	int count, i;
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
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			int j;

			i++;
			for (j = 0; j < 5; j++)
			{
				if (format[i] == specifiers[j])
				{
					count += print_func[j](args);
					break;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

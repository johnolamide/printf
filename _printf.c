#include "main.h"
/**
 * print_char - print char arguments
 * @args: va_list argument
 * Return: return char number
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
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
	int num = va_arg(args, int);
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
	if (i >= 11)
		return (-1);
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

	int count = 0, i;
	va_list args;
	int (*print_func[5])(va_list) = {print_char, print_string,
	print_percent, print_int, print_int};
	char specifiers[5] = {'c', 's', '%', 'd', 'i'};

	va_start(args, format);

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

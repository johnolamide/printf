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
	int i;
	int count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
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
 * _printf - produces output to a format
 * @format: character string argument
 * Return: returns an int value
 */
int _printf(const char *format, ...)
{
	int count;
	int i;
	va_list args;
	int (*print_func[3])(va_list);
	char specifiers[3];

	va_start(args, format);
	print_func[0] = print_char;

	print_func[1] = print_string;
	
	print_func[2] = print_percent;

	specifiers[0] = 'c';
	
	specifiers[1] = 's';
	
	specifiers[2] = '%';

	count = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			int j;

			i++;
			for (j = 0; j < 3; j++)
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

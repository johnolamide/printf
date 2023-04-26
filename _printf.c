#include "main.h"

void print_buffer (char buffer[], int *buff_ind);

/**
 * _printf - produces output to a format
 * @format: character string argument
 * Return: returns an int value
 */

int _printf(const char *format, ...)
{
	int n, print_type = 0, char_print = 0;
	int f, y, pre, s, buff_ind = 0;
	va_list list;
	char buffer(BUFF_SIZE);

	if (format == NULL)
		return(-1);

	va_start(list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '\0')
		{
			buffer(buff_ind++) = format[n];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			char_print++;
		}

		else
		{
			print_buffer(buffer, &buff_ind);
			f = get_f(format, &n);
			y = get_y(format, &n, list);
			pre = get_s(format, &n);
			s = get_s(format, &n);
			++n;
			print_type = handle_print(format, &n, list, buffer, f, y, pre, s);
			if (print_type == -1)
				return (-1);
			char_print += print_type;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (char_print);
}

/**
 * print_buffer - print the result of the buffer
 * @buffer: character array
 * @buff_ind: Index for character, showing lenght
 */
void print_buffer((char buffer[]), int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

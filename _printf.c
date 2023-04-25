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
        str = "(null)";

    while (*str)
    {
        _putchar(*str++);
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
 * _printf - produces output according to a format
 * @format: character string argument
 * Return: returns an int value
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
                count += print_percent(args);
                break;
            case '\0':
                va_end(args);
                return (-1);
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

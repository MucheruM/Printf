#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * process_specifier - Helper function to process format specifiers
 * @spec: the characters to be processed
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int process_specifier(char spec, va_list args)
{
	int count = 0;
	int result;
	const char *str;

	switch (spec)
	{
	case 'c':
		_putchar(va_arg(args, int)); /* Output a character */
		count++;
		break;

	case 's':
	{
		str = va_arg(args, const char *);
		while (*str)
		{
			_putchar(*str);
			str++;
			count++;
		}
		break;
	}

	case '%':
		_putchar('%');
		count++;
		break;

	default:
		return (-1); /* Unknown specifier */
	}

	return (count);
}

/**
 * _printf - Print characters in the stdout
 * @format: the characters to be printed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	int result;

	if (!format)
		return (-1);

	va_start(args, format);

	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			result = process_specifier(*ptr, args);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
		}
		else
		{
			_putchar(*ptr);
			count++;
		}
	}

	va_end(args);
	return (count);
}

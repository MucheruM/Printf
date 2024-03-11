#include "main.h"

/**
 * _printf - This is a printf function
 * @format: A parameter holding a string to be printed
 * Return: An integer value
 */
int _printf(const char *format, ...)
{
	int char_print = 0;

	va_list list_args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list_args, format);

	while (*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			char_print ++;
		}
		else /* If format is a % */
		{
			format++; /* Skips to next char after % */

			if (*format == '\0')
				break;

			if (*format == '%') /* Solves %% */
			{
				write(1, format, 1);
				char_print++;
			}

			else if (*format == 'c')
			{
				char c = va_arg(list_args, int);
				write(1, &c, 1);
				char_print++;
			}

			else if (*format == 's')
			{
				char *str = va_arg(list_args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				char_print += str_len;
			}
		}

		format++;
	}

	va_end(list_args);

	return char_print;
}

int main()
{
	_printf("Mucheru Printf Assignment\n");
	_printf("%c\n", 'M');
	_printf("%s\n", "MucheruM");
	_printf("%%\n");

	return (0);
}

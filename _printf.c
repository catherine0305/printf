#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - a printf function
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int im, l = 0;
	va_list ca;

	va_start(ca, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (im = 0; format[im] != '\0'; im++)
	{
		if (format[im] == '\0')
			break;
		if (format[im] == '%')
		{
			if (format[im + 1] == '%')
			{
				_putchar('%');
				l++;
			}
			else if (format[im + 1] == 'd' || format[im + 1] == 'i')
			{
				l = print_num(ca, l);
			}
			else if (format[im + 1] == 'c')
			{
				l = print_char(ca, l);
			}
			else if (format[im + 1] == 's')
			{
				l = print_str(ca, l);
			}
			im++;
		}
		else
		{
			_putchar(format[im]);
			l++;
		}
	}
	va_end(ca);
	return (l);
}

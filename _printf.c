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
	int im, l = 0, s_l;
	va_list ca;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ca, format);

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
			else if (format[im + 1] == 'c')
			{
				_putchar(va_arg(ca, int));
				im++;
			}
			else if (format[im + 1] == 's')
			{
				s_l = putsss(va_arg(ca, char *));
				im++;
				l += (s_l - 1);
			}
			im++;
		}
		else if (format[im] != '%')
		{
			_putchar(format[im]);
		}
	}
	va_end(ca);
	return (l);
}

#include "main.h"
void print_buffer(char buffer[], int *buff_in);
/**
 * _printf - a printf function
 * @format: format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int i, prin = 0, prin_chars = 0;
	int flags, width, precision, size, buff_in = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_in++] = format[i];
			if (buff_in == BUFFER_SIZE)
				print_buffer(buffer, &buff_in);
			/*write(1, &format[i], 1);*/
			prin_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_in);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			prin = handle_print(format, &i, list, buffer, flags,
					width, precision, size);
			if (prin == -1)
				return (-1);
			prin_chars += prin;
		}
	}
	print_buffer(buffer, &buff_in);

	va_end(list);

	return (prin_chars);
}
/**
 * print_buffer - prints the contents of buffer
 * @buffer: array of characters
 * @buff_in: index to add next character
 */
void print_buffer(char buffer[], int *buff_in)
{
	if (*buff_in > 0)
		write(1, &buffer[0], *buff_in);
	*buff_in = 0;
}

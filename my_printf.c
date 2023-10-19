#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Function for printing formatted output
 * @format: The format string
 * Return: Number of characters to be printed.
 */
int _printf(const char *format, ...)
{
	int i, to_print = 0, len = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list my_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(my_list, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);
			len++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, my_list);
			precision = get_precision(format, &i, my_list);
			size = get_size(format, &i);
			++i;
			to_print = handle_print(format, &i, my_list, buffer,
				flags, width, precision, size);
			if (to_print == -1)
				return (-1);
			len += to_print;
		}
	i++;
	}

	print_buffer(buffer, &buffer_index);

	va_end(my_list);

	return (len);
}

/**
 * print_buffer - Print the buffer's contents if it's present
 * @buffer: Character array
 * @buffer_index: Index for the next character, indicating buffer length
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}


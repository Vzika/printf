#include "main.h"
/**
 * _printf - Prints and handle various specifiers
 * @format: Input string with format specifier
 *
 * Return: Len.
 */
int _printf(const char *format, ...)
{
	va_list my_list;
	size_t length = 0, i = 0, j, size_of_array;
	char newline = '\n';
	print arr[10] = {
	{'c', print_char}, {'s', print_str}, {'%', print_modulus}, {'d', print_int}, {'i', print_int}, {'b', print_binary}, {'u', print_unsigned}, {'o', print_octal}, {'x', print_hex_lower}, {'X', print_hex_upper},
};
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (0);
	size_of_array = sizeof(arr) / sizeof(arr[0]);
	va_start(my_list, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			length++;
		}
		else
		{
			i++;
			j = 0;
			for (j = 0; j < size_of_array; j++)
			{
				if (format[i] == arr[j].type_specifier)
				{
					length += arr[j].print(my_list);
					break;
				}
			}
			if (j == size_of_array)
			{
				char percent = '%';

				write(1, &percent, 1);
				write(1, &format[i], 1);
				length += 2;
			}
		}
	}
	if (format[i] == '\n')
		write(1, &newline, 1);
	return (length);
	va_end(my_list);
}

int main()
{
	_printf("%s %d %c", "hello",30, 't');
	printf("%s %d %c", "hello",30, 't');
	return(0);
}

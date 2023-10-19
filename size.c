#include "main.h"

/**
 * get_size - Determine the size of a format specifier.
 * @format: Formatted string specifying the format specifier..
 * @i: Pointer.
 * Return: An integer representing the size specification.
 */
int get_size(const char *format, int *i)
{
	int current_i = *i + 1;
	int size = 0;

	if (format[current_i] == 'l')
		size = S_LONG;
	else if (format[current_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (size);
}


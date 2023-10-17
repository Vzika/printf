#include "main.h"
/**
 * print_int - the function that holds the num;
 * @list: lists of numbers to print
 *
 * Return:lenght of numbers printed
 */
int print_int(va_list list)
{
	int num;
	int is_negative;
	int length;
	int num_copy;
	int i;
	char *digits;

	num = va_arg(list, int);

	is_negative = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		is_negative = 1;
		num = -num;
	}
	length = 0;
	num_copy = num;
	for (length = 0; num_copy != 0; length++)
		num_copy /= 10;
	digits = (char *)malloc(length * sizeof(char));
	for (i = length - 1; i >= 0; i--)
	{
		digits[i] = ((num % 10) + '0');
		num /= 10;
	}
	write(1, digits, length);
	free(digits);
	return (length + (is_negative ? 1 : 0));
}


#include "main.h"

/**
 * print_unsigned - Print an unsigned number.
 * @list: Argument list.
 * @buff: Buffer for printing.
 * @flags: Active formatting flags.
 * @width: Width for formatting.
 * @precision: Precision settings.
 * @size: Size specification.
 * Return: Number of printed characters.
 */

int print_unsigned(va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}

/**
 * print_octal - Print an unsigned number in octal format.
 * @list: Argument list.
 * @buff: Printing buffer.
 * @flags: Active formatting flags.
 * @width: Formatting width.
 * @precision: Formatting precision.
 * @size: Size specifier.
 * Return: Number of printed characters.
 */

int print_octal(va_list list, char buff[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while(number > 0)
	{
		buff[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_number != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}

/**
 * print_hexadecimal - Print an unsigned number in hexadecimal.
 * @list: Argument list.
 * @buff: Printing buffer.
 * @flags: Active formatting flags.
 * @width: Formatting width.
 * @precision: Formatting precision.
 * @size: Size specifier.
 * Return: Number of printed characters.
 */
int print_hexadecimal(va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}


int print_hexa_upper(va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Print a hexadecimal number in lower or upper case.
 * @list: Argument list.
 * @map_to: Value mapping array.
 * @buff: Print buffer.
 * @flags: Active formatting flags.
 * @flag_ch: Active flags.
 * @width: Formatting width.
 * @precision: Formatting precision.
 * @size: Size specifier.
 * Return: Number of printed characters.
 */
int print_hexa(va_list list, char map_to[], char buff[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}


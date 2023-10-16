#include "main.h"
/**
 * print_char - Print a character
 * @list: A va_list containing the character to print
 *
 * Return: The number of characters printed (always 1)
 */

int print_char(va_list list)
{
	char c = va_arg(list, int);
	write(1, &c, 1);
	return 1;
}

/**
 * print_str - Print a string
 * @list: A va_list containing the string to print
 *
 * Return: The number of characters printed
 */

int print_str(va_list list)
{
	size_t i;
	char *str = va_arg(list, char *);

	if (str == NULL)
		str = "(null)";

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return i;
}

/**
 * print_modulus - Print the percentage character
 * @list: A va_list (unused)
 *
 * Return: The number of characters printed (always 1)
 */

int print_modulus(va_list list)
{
	char c;

	(void)list;
	c = '%';
	write(1, &c, 1);
	return 1;
}


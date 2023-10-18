#include "main.h"

/**
 * base_change - function to change a positive integer to a different base
 * @n: the number
 * @base: the new base
 *
 * Return: the number of characters printed
 */
int base_change(unsigned int n, unsigned int base)
{
	int newdigit = 0;

	if (base < 2 || base > 36)
	{
		return (-1);
	}

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		int digit = n % base;

		if (digit < 10)
			_putchar(digit + '0');
		else
			_putchar(digit + 'A' - 10);

		n /= base;
		newdigit++;
	}

	return (newdigit);
}

/**
 * print_binary - function to print a binary number
 * @b: parameters
 * Return: the number of digits printed
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_binary(va_list b)
{
	unsigned int n = va_arg(b, unsigned int);

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	else if (n > 0)
	{
		return (base_change(n, 2));
	}

	return (-1);
}


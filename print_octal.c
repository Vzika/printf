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
 * printOctal - function to print an octal number
 * @args: argument list
 * Return: the number of digits printed
 */
int printOctal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count = base_change(n, 8);
	}

	return (count);
}


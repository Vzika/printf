#include "main.h"
/**
 * print_hex_upper - function that holds hex number to be print
 * @list: list of numbers to print
 *
 * Return: lenght of the hexa num printed
 */

int print_hex_upper(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int len = 0;
	unsigned int temp = num;
	char *hex;
	int i;
	int remainder;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (temp != 0)
	{
		temp /= 16;
		len++;
	}

	hex = (char *)malloc(len * sizeof(char));

	for (i = len - 1; i >= 0; i--)
	{
		remainder = num % 16;
		if (remainder < 10)
		{
			hex[i] = remainder + '0';
		}
		else
		{
			hex[i] = remainder - 10 + 'A';
		}
		num /= 16;
	}

	write(1, hex, len);
	free(hex);

	return (len);
}


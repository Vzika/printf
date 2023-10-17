#include "main.h"
/**
 * print_binary- function that holds num tp be printed
 * @list: list of numbers to print
 * Return: lenght of numbers printed
 */

int print_binary(va_list list)
{
	unsigned int i;
	unsigned int num = va_arg(list, unsigned int);
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int len = 0;
	int flag = 0;

	if (num == 0)
	{
	write(1, "0", 1);
	return (1);
	}
	for (i = 0; i < sizeof(unsigned int) * 8; i++)
	{
	if (num & mask)
	write(1, "1", 1);
	flag = 1;
	len++;
	}
	else if (flag)
	{
	write(1, "0", 1);
	len++;
	}
	mask >>= 1;
	}
	return (len);
}


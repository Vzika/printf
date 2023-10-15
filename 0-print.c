#include "main.h"
int print_char(va_list list)
{
	char c = va_arg(list, int);
	write(1,&c,1);
	return(1);
}

int print_str(va_list list)
{
	int i,len=0;
	char *str = va_arg(list, char *);
	for(i=0;str[i] != '\0'; i++)
	{
		len++;
	}
	write(1,str,len);
	return(len);
}

int print_modulus(va_list list)
{
	char z = '%';
	write(1, &z,1);
	return(1);
}

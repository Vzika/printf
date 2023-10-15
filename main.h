#ifndef MAIN_H
#define MAIN_H

#include<string.h>
#include<unistd.h>
#include<stdarg.h>
#include<stdio.h>

typedef struct format_specifiers
{
	char specifier_type;
	int (*print)(va_list list);
}print;


int _printf(const char *format, ...);
int print_char(va_list list);
int print_str(va_list list);
int print_modulus(va_list list);




#endif

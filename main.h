#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type of element
 * @f: function to print
 */
typedef struct print
{
	char *type;
	int (*func)(va_list);
} struct;
int _putchar(char c);
int _printf(const char *format, ...);
int change_base(unsigned int n, int newdigit, unsigned int base);
int print_c(va_list c);
int print_s(va_list s);
int print_d(va_list d);
int print_i(va_list i);
int print_b(va_list b);
int print_o(va_list o);
#endif


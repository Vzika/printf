#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
/**
 * struct print - structure for printing various types
 * @t: type of element
 * @f: function to print
 */
typedef struct print
{
	char *type;
	int (*func)(va_list);
} print_t;

void print_char(char c, int *char_count);
void print_string(const char *s, int *char_count);
int _putchar(char c);
int _printf(const char *format, ...);
int base_change(unsigned int n, unsigned int base);
int printOctal(va_list args);
int print_c(va_list c);
int print_s(va_list s);
int print_d(va_list d);
int print_i(va_list i);
int print_b(va_list b);
int print_o(va_list o);
#endif


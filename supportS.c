#include <unistd.h>

/**
 * print_string - Print a string to the standard output.
 * @s: The string to print.
 * @char_count: Pointer to the character count.
 */
void print_string(const char *s, int *char_count)
{
	while (*s)
	{
		write(1, s, 1);
		(*char_count)++;
		s++;
	}
}


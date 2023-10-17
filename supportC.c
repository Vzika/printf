#include <unistd.h>

/**
 *_print_char - Print a character to the standard output
 * @c: The character to print
 * @char_count: Pointer to the character count
 */
void print_char(char c, int *char_count)
{
	write(1, &c, 1);
	(*char_count)++;
}

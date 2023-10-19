#include "main.h"

/**
 * handle_write_char - Print a character with formatting options.
 * @c: Character to be printed
 * @buffer: Character buffer for printing.
 * @flags: Flags that control formatting.
 * @width: Width specifier.
 * @preciision: Precision specifier.
 * @size: Size specifier.
 * Return: The number of characters printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int preciision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(preciision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Format and print a number as a string.
 * @is_negative: Tells if the number is negative.
 * @ind: Character types.
 * @buffer: Character buffer for printing.
 * @flags: Extracts flag characters.
 * @width: Width specifier.
 * @preciision: Precision specifier.
 * @size: Size specifier.
 * Return: The number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int preciision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, preciision,
		len, pad, extra_ch));
}


int write_num(int ind, char buffer[],
	int flags, int width, int preci,
	int len, char pad, char extra_c)
{
	int i, pad_start = 1;

	if (preci == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (preci == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (preci > 0 && preci < len)
		pad = ' ';
	while (preci > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], len - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}

/**
  * write_unsgnd - Format and print an unsigned number
  * @is_negative: Tells if the number is negative
  * @ind: Starting index of the number in the character buffer
  * @buffer: Array of characters for printing
  * @flags: Flag specifier
  * @width: Width specifier
  * @preciision: Precision specifier
  * @size: Size specifier
  *
  * Return: The number of characters written
  */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int preciision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (preciision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (preciision > 0 && preciision < len)
		pad = ' ';

	while (preciision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - Format and print a memory address
 * @buffer: Character buffer for storing the formatted address
 * @ind: Starting index of the address in the buffer
 * @len: Length of the formatted address
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Character used for padding
 * @extra_c: Extra character
 * @pad_start: Index at which padding should start
 *
 * Return: The number of written characters
 */
int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char pad, char extra_c, int pad_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], len - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}


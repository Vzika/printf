#include "main.h"

int print_binary(va_list list)
{
	unsigned int i;
    unsigned int num = va_arg(list, unsigned int);
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int len = 0;
    int flag = 0;

    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }

    for (i = 0; i < sizeof(unsigned int) * 8; i++) {
        if (num & mask) {
            write(1, "1", 1);
            flag = 1;
            len++;
        } else if (flag) {
            write(1, "0", 1);
            len++;
        }
        mask >>= 1;
    }

    return len;
}

int print_unsigned(va_list list) {
    unsigned int num = va_arg(list, unsigned int);
    unsigned int num_copy = num;
	char *digits;
    int len;
	int i;

    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }

    for (len = 0; num_copy != 0; len++) {
        num_copy /= 10;
    }

    digits = (char *)malloc(len * sizeof(char));

    for (i = len - 1; i >= 0; i--) {
        digits[i] = num % 10 + '0';
        num /= 10;
    }

    write(1, digits, len);
    free(digits);

    return len;
}

int print_octal(va_list list) {
    unsigned int num = va_arg(list, unsigned int);
    int len = 0;
    unsigned int temp = num;
    char *octal;
	int i;

    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }

    while (temp != 0) {
        temp /= 8;
        len++;
    }

    octal = (char *)malloc(len * sizeof(char));

    for (i = len - 1; i >= 0; i--) {
        octal[i] = num % 8 + '0';
        num /= 8;
    }

    write(1, octal, len);
    free(octal);

    return len;
}

int print_hex_lower(va_list list) {
    unsigned int num = va_arg(list, unsigned int);
    int len = 0;
    unsigned int temp = num;
    char *hex;
	int i;
	int remainder;

    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }

    while (temp != 0) {
        temp /= 16;
        len++;
    }

    hex = (char *)malloc(len * sizeof(char));

    for (i = len - 1; i >= 0; i--) {
        remainder = num % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'a';
        }
        num /= 16;
    }

    write(1, hex, len);
    free(hex);

    return len;
}

int print_hex_upper(va_list list) {
    unsigned int num = va_arg(list, unsigned int);
    int len = 0;
    unsigned int temp = num;
    char *hex;
	int i;
	int remainder;

    if (num == 0) {
        write(1, "0", 1);
        return 1;
    }

    while (temp != 0) {
        temp /= 16;
        len++;
    }

    hex = (char *)malloc(len * sizeof(char));

    for (i = len - 1; i >= 0; i--) {
        remainder = num % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A';
        }
        num /= 16;
    }

    write(1, hex, len);
    free(hex);

    return len;
}


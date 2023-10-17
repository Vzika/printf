#include "main.h"

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


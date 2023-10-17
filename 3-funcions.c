#include "main.h"

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


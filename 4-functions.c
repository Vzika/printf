#include "main.h"

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


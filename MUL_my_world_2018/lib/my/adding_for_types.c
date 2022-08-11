/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

void hexa_convert(long a)
{
    int  i = 0;
    long u = 0;
    char *hex = malloc(sizeof(char) * 20);

    while (a != 0) {
        u = a % 16;
        if (u > 9)
            hex = call_hex_convert(u, hex, i);
        else if (u < 10)
            hex[i] = u + 48;
        a = a / 16;
        i = i + 1;
    }
    hex[i] = '\0';
    my_revstr(hex);
    my_putstr(hex);
    free(hex);
    return;
}

void oct_convert(int oct_conv)
{
    int z = 0;
    char *oct = malloc(sizeof(char) * oct_conv);

    while (oct_conv != 0) {
        oct[z] = (oct_conv % 8) + 48;
        oct_conv = oct_conv / 8;
        z = z + 1;
    }
    oct[z] = '\0';
    my_revstr(oct);
    my_putstr(oct);
    free(oct);
    return;
}

void case_u(va_list ap)
{
    my_put_nbr(va_arg(ap, long));
    return;
}

void case_pourcent(void)
{
    my_putchar('%');
    return;
}

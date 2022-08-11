/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

void case_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
    return;
}

void case_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
    return;
}

void case_ss(va_list ap, int len)
{
    int i = 0;
    int oct_conv;
    char *str = malloc(sizeof(char) * (len + 3));

    my_strcpy(str, va_arg(ap, char *));
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            oct_conv = str[i];
            oct_convert(oct_conv);
        } else
            my_putchar(str[i]);
        i = i + 1;
    }
    return;
}

void case_p(va_list ap)
{
    long a = (va_arg(ap, long));

    hexa_convert(a);
    return;
}

void case_d(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return;
}

/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

void put_maj(char *hex)
{
    int i = 0;

    while (hex[i] != '\0') {
        if (hex[i] > 96 && hex[i] < 123)
            hex[i] = hex[i] - 32;
        i = i + 1;
    }
    my_putstr(hex);
    free(hex);
}

void case_xx(va_list ap)
{
    int a = va_arg(ap, int);
    int i = 0;
    int u = 0;
    char *hex = malloc(sizeof(char) * 200);

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
    put_maj(hex);
    free(hex);
    return;
}

void switch_type_3(char **pars, int cell, va_list ap, int len)
{
    if (pars[cell][len] == 'u' || pars[cell][len] == 'l')
        case_u(ap);
    if (pars[cell][len] == '%')
        case_pourcent();
    if (pars[cell][len] == 'b')
        case_b(ap);
    return;
}

void switch_type_2(char **pars, int cell, va_list ap, int len)
{
    if (pars[cell][len] == 'c')
        case_c(ap);
    if (pars[cell][len] == 's')
        case_s(ap);
    if (pars[cell][len] == 'S')
        case_ss(ap, len);
    if (pars[cell][len] == 'p')
        case_p(ap);
    return;
}

void switch_type_1(char **pars, int cell, va_list ap)
{
    int len = my_strlen(pars[cell]) - 1;

    if (pars[cell][len] == 'd' || pars[cell][len] == 'i')
        case_d(ap);
    if (pars[cell][len] == 'o')
        case_o(ap);
    if (pars[cell][len] == 'x')
        case_x(ap);
    if (pars[cell][len] == 'X')
        case_xx(ap);
    switch_type_2(pars, cell, ap, len);
    switch_type_3(pars, cell, ap, len);
    return;
}

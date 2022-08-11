/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

char *call_hex_convert(int u, char *hex, int i)
{
    if (u == 10)
        hex[i] = 'a';
    if (u == 11)
        hex[i] = 'b';
    if (u == 12)
        hex[i] = 'c';
    if (u == 13)
        hex[i] = 'd';
    if (u == 14)
        hex[i] = 'e';
    if (u == 15)
        hex[i] = 'f';
    return (hex);
}

void case_o(va_list ap)
{
    int a = va_arg(ap, int);
    int i = 0;
    char *oct = malloc(sizeof(char) * (a * 10));

    while (a != 0) {
        oct[i] = (a % 8) + 48;
        a = a / 8;
        i = i + 1;
    }
    oct[i] = '\0';
    my_revstr(oct);
    my_putstr(oct);
    free(oct);
    return;
}

void case_x(va_list ap)
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
    my_putstr(hex);
    free(hex);
    return;
}

void case_b(va_list ap)
{
    int a = va_arg(ap, int);
    int i = 0;
    char *bin = malloc(sizeof(char) * (a * 10));

    while (a != 0) {
        bin[i] = (a % 2) + 48;
        a = a / 2;
        i = i + 1;
    }
    bin[i] = '\0';
    my_revstr(bin);
    my_putstr(bin);
    free(bin);
    return;
}

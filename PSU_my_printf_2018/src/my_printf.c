/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** same as the C printf function
*/

#include <stdarg.h>
#include "my.h"

int count_nbr_digit(int nb)
{
    int i = 1;

    for (i = 1; nb > 9; i++) {
        nb = nb / 10;
    }
    return (i);
}

int my_non_printable(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] == 127)
            my_putstr(convert_to_octal(str[i]));
        else
            my_putchar(str[i]);
    }
    return (i);
}

int my_printf(char const *format, ...)
{
    va_list list;
    int ct = 0;

    va_start(list, format);
    for (int i = 0; format[i]; i = i + 1) {
        for (;format[i] != '%'; i = i + 1) {
            my_putchar(format[i]);
        }
        check_and_print(&list, format, &i, &ct);
    }
    return (ct);
}
/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** printf function
*/

#include "my_printf.h"
#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>

void non_printable(char const *format, int *i)
{
    switch (format[*i + 1]) {
    case 'n':
        my_putstr("\n");
        *i = *i + 1;
        break;
    case 'b':
        my_putstr("\b");
        *i = *i + 1;
        break;
    case 't':
        my_putstr("\t");
        *i = *i + 1;
        break;
    default:
        break;
    }
}

int my_printf(char const *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%' && format[i] != 92)
            my_putchar(format[i]);
        else if (format[i] == 92)
            non_printable(format, &i);
        else
            find_format_and_print(format, &i, &list);
    }
    va_end(list);
    return (1);
}

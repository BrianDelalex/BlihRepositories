/*
** EPITECH PROJECT, 2018
** dist_starg.c
** File description:
** displays arguments followed by \n
*/

#include <stdarg.h>
#include "my.h"

int disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i]; i = i + 1) {
        if (s[i] == 'c')
            my_putchar(va_arg(list, int));
        if (s[i] == 's')
            my_putstr(va_arg(list, char *));
        if (s[i] == 'i')
            my_putnbr(va_arg(list, int));
        my_putchar('\n');
    }
    va_end(list);
    return (0);
}
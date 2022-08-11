/*
** EPITECH PROJECT, 2018
** sum_stdarg.c
** File description:
** return the sum of last arguments nb if i = 0 and \
return the sum of the size of the last char * if i = 1
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int sum_size(int nb, va_list list)
{
    int res = 0;

    for (int i = nb; i > 0; i --) {
        res += my_strlen(va_arg(list, char *));
    }
    va_end(list);
    return (res);
}

int sum_nb(int nb, va_list list)
{
    int res = 0;

    for (int i = nb; i > 0; i--) {
        res += va_arg(list, int);
    }
    va_end(list);
    return (res);
}

int sum_stdarg(int i, int nb, ...)
{
    va_list list;

    va_start(list, nb);
    if (i == 0)
        return (sum_nb(nb, list));
    if (i == 1)
        return (sum_size(nb, list));
    va_end(list);
}

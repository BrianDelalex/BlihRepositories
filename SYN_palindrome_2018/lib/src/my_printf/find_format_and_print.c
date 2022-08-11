/*
** EPITECH PROJECT, 2019
** find_format_and_print.c
** File description:
** finds the format and prints
*/

#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>

int find_format_and_print2(char const *format, int *i, va_list *list)
{
    if (my_strncmp(format + *i, "%f", 2)) {
        my_putdouble(va_arg(*list, double), 6);
        *i = *i + 1;
        return (1);
    }
    if (my_strncmp(format + *i, "%.", 2) && IS_DIGIT(format[*i + 2]) &&
    format[*i + 3] == 'f') {
        my_putdouble(va_arg(*list, double), format[*i + 2] - 48);
        *i = *i + 3;
        return (1);
    }
    return (0);
}

int find_format_and_print(char const *format, int *i, va_list *list)
{
    char *tmp = NULL, c;

    if (my_strncmp(format + *i, "%s", 2) == 1) {
        tmp = my_strdup(tmp, va_arg(*list, char *));
        my_putstr(tmp);
        *i = *i + 1;
        free(tmp);
        return (1);
    }
    if (my_strncmp(format + *i, "%c", 2) == 1) {
        c = va_arg(*list, int);
        my_putchar(c);
        *i = *i + 1;
        return (1);
    }
    if (my_strncmp(format + *i, "%d", 2) == 1) {
        my_putnbr(va_arg(*list, int));
        *i = *i + 1;
        return (1);
    }
    return (find_format_and_print2(format, i, list));
}

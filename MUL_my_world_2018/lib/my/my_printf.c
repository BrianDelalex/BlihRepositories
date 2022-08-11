/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

void switch_putstr(char **pars, int cell, int i)
{
    if (pars[cell][i] == 'n')
        my_putchar('\n');
    if (pars[cell][i] == 't')
        my_putchar('\t');
    if (pars[cell][i] == 'a')
        my_putchar('\a');
    if (pars[cell][i] == 'b')
        my_putchar('\b');
    if (pars[cell][i] == 'v')
        my_putchar('\v');
    if (pars[cell][i] == 'f')
        my_putchar('\f');
    if (pars[cell][i] == 'r')
        my_putchar('\r');
}

void my_pustr_remix(char **pars, int cell)
{
    int i = 0;

    while (pars[cell][i] != '\0') {
        if (pars[cell][i] == '\\') {
            i = i + 1;
            switch_putstr(pars, cell, i);
            i = i + 1;
        } else {
            my_putchar(pars[cell][i]);
            i = i + 1;
        }
    }
}

int my_printf(char const *format, ...)
{
    va_list ap;
    int i = 0, cell = 0;
    char **pars = malloc(sizeof(char *) * (my_strlen(format) + 1));

    while (i != my_strlen(format)) {
        pars[i] = malloc(sizeof(char) * (my_strlen(format) + 1));
        i = i + 1;
    }
    pars = fill_in_pars(format, pars);
    va_start(ap, format);
    while (pars[cell] && pars[cell][0] != '\0') {
        if (pars[cell][0] == '%')
            switch_type_1(pars, cell, ap);
        else if (pars[cell][0] != '%')
            my_pustr_remix(pars, cell);
        cell = cell + 1;
    }
    va_end(ap);
    return (0);
}

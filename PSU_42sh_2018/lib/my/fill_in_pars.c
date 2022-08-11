/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

char **call_to_str(char const *format, int *i, int *cell, char **pars)
{
    int z = 0;

    while (format[*i] != '\0' && format[*i] != '%') {
        pars[*cell][z] = format[*i];
        *i = *i + 1;
        z = z + 1;
    }
    pars[*cell][z] = '\0';
    *i = *i - 1;
    return (pars);
}

char **fill_in_pars(char const *format, char **pars)
{
    int i = 0, cell = 0;

    while (format[i] != '\0') {
        while (format && format[i] == '%') {
            pars[cell][0] = format[i];
            pars[cell][1] = format[i + 1];
            pars[cell][2] = '\0';
            i = i + 2;
            cell = cell + 1;
        }
        if (format && format[i] != '%')
            pars = call_to_str(format, &i, &cell, pars);
        cell = cell + 1;
        i = i + 1;
    }
    pars[cell] = NULL;
    return (pars);
}

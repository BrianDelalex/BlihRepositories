/*
** EPITECH PROJECT, 2018
** check_and_print.c
** File description:
** check for form and print the right thing
*/

#include <stdarg.h>
#include "my.h"

void check_and_print3(va_list *list, char const *form, int *i, int *ct)
{
    char *c_tmp;
    int tmp = 0;

    if (form[*i] == '%' && form[*i + 1] == 'x') {
        c_tmp = my_strcpy(c_tmp, convert_to_hexa(va_arg(*list, int), 32));
        *ct = *ct + my_strlen(c_tmp);
        my_putstr(c_tmp);
    }
    if (form[*i] == '%' && form[*i + 1] == 'X') {
        c_tmp = my_strcpy(c_tmp, convert_to_hexa(va_arg(*list, int), 0));
        *ct = *ct + my_strlen(c_tmp);
        my_putstr(c_tmp);
    }
    if (form[*i] == '%' && form[*i + 1] == '%') {
        my_putchar('%');
        *ct = *ct + 1;
    }
    *i = *i + 1;
}

void check_and_print2(va_list *list, char const *form, int *i, int *ct)
{
    char *char_tmp;
    int tmp = 0;

    if (form[*i] == '%' && form[*i + 1] == 'b') {
        char_tmp = my_strcpy(char_tmp, convert_to_binarie(va_arg(*list, int)));
        *ct = *ct + my_strlen(char_tmp);
        my_putstr(char_tmp);
    }
    if (form[*i] == '%' && form[*i + 1] == 'c') {
        *ct = *ct + 1;
        my_putchar(va_arg(*list, int));
    }
    if (form[*i] == '%' && form[*i + 1] == 'o') {
        char_tmp = my_strcpy(char_tmp, convert_to_octal(va_arg(*list, int)));
        *ct = *ct + my_strlen(char_tmp);
        my_putstr(char_tmp);
    }
    check_and_print3(list, form, i, ct);
}

void check_and_print(va_list *list, char const *form, int *i, int *ct)
{
    int tmp = 0;
    char *char_tmp;

    if (form[*i] == '%' && form[*i + 1] == 'S')
        *ct = *ct + my_non_printable(va_arg(*list, char *));
    if (form[*i] == '%' && (form[*i + 1] == 'd' || form[*i + 1] == 'i')) {
        tmp = va_arg(*list, int);
        *ct = *ct + count_nbr_digit(tmp);
        my_putnbr(tmp);
    }
    if (form[*i] == '%' && form[*i + 1] == 's') {
        char_tmp = my_strcpy(char_tmp ,va_arg(*list, char *));
        *ct = *ct + my_strlen(char_tmp);
        my_putstr(char_tmp);
    }
    check_and_print2(list, form, i, ct);
}
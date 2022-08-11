/*
** EPITECH PROJECT, 2019
** change_base.c
** File description:
** take an int and return in good base
*/

#include "../include/my.h"

char *change_base_to_char(int nb, int base)
{
    int len =  0;
    int rtn = 0;
    int save = nb;
    char *str;

    for (;save > 0; len++)
        save = save / base;
    str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; nb > 0; i++) {
        rtn = nb % base;
        nb = nb / base;
        str[i] = rtn + 48;
    }
    str[len] = 0;
    return (str);
}

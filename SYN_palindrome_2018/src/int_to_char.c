/*
** EPITECH PROJECT, 2019
** int_to_char.c
** File description:
** int to char
*/

#include "../include/my.h"

char *int_to_char(int nb)
{
    char *str;
    int save = nb;
    int len = 0;

    for (; save != 0; len++, save = save / 10);
    str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; nb != 0; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[len] = 0;
    return (my_revstr(str));
}

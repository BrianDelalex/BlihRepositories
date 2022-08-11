/*
** EPITECH PROJECT, 2019
** remove_unwanted_char.c
** File description:
** remove unwanted char
*/

#include "../include/my.h"

int is_in_str(char c, char *tab)
{
    for (int i = 0; tab[i]; i++)
        if (c == tab[i])
            return (1);
    return (0);
}

char *remove_unwanted_char(char *str, char *want)
{
    int len = 0;
    char *new;
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (is_in_str(str[i], want))
            len = len + 1;
    new = malloc(sizeof(char) * (len + 1));
    for (int i = 0; str[i]; i++, j++)
        if (is_in_str(str[i], want))
            new[j] = str[i];
        else
            j--;
    new[len] = 0;
    return (new);
}

/*
** EPITECH PROJECT, 2019
** my_puttab.c
** File description:
** displays the given char **
*/

#include "utils.h"

void my_puttab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}

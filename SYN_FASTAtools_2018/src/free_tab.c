/*
** EPITECH PROJECT, 2019
** free_tab.c
** File description:
** free char **
*/

#include "../include/my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

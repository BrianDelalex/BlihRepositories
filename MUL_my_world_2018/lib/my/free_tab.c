/*
** EPITECH PROJECT, 2018
** free_tab.c
** File description:
** free_tab
*/

#include "../../include/my.h"

void free_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

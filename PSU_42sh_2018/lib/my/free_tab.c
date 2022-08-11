/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../../include/my.h"

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

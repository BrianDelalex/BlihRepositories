/*
** EPITECH PROJECT, 2019
** free_char_tab.c
** File description:
** free a char**
*/

#include <stdlib.h>

void free_char_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

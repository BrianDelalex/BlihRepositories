/*
** EPITECH PROJECT, 2019
** is_in_tab.c
** File description:
** true if the str is in the tab
*/

#include "utils.h"
#include <stdlib.h>

int is_in_tab(char **tab, char *str)
{
    int check = 0;

    if (str == NULL)
        return (-1);
    if (tab == NULL)
        return (0);
    for (int i = 0; tab[i]; i++)
        if (my_strcmp(tab[i], str))
            check = 1;
    return (check);
}

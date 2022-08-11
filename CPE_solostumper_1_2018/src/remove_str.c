/*
** EPITECH PROJECT, 2019
** remove_str.c
** File description:
** removes str from char**
*/

#include <stdlib.h>

char **remove_str(char **tab, int index)
{
    char **new_tab;
    int len = 0;
    int j = 0;

    for (; tab[len]; len = len + 1);
    new_tab = malloc(sizeof(char *) * len);
    for (int i = 0; tab[i]; i++, j++) {
        if (i == index)
            j = j - 1;
        else
            new_tab[j] = tab[i];
    }
    new_tab[j] = 0;
    return (new_tab);
}

/*
** EPITECH PROJECT, 2019
** remove_str.c
** File description:
** removes str from char **
*/

#include <stdlib.h>

char **remove_str_to_tab(char **tab, int index)
{
    char **new_tab;
    int len = 0, j = 0;

    for (; tab[len]; len = len + 1);
    if (index == len - 1) {
        tab[len - 1] = NULL;
        return (tab);
    }
    if (len == 1)
        return (NULL);
    new_tab = malloc(sizeof(char *) * (len + 1));
    if (new_tab == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++, j++) {
        if (i == index)
            j = j - 1;
        else
            new_tab[j] = tab[i];
    }
    new_tab[j] = 0;
    return (new_tab);
}

/*
** EPITECH PROJECT, 2019
** add_int_list_to_tab.c
** File description:
** add a int* to a int**
*/

#include "../include/my.h"

int **add_int_list_to_tab(int **tab, int *add)
{
    int **new;
    int len = 0;

    if (tab == NULL) {
        new = malloc(sizeof(int *) * 2);
        new[0] = add;
        new[1] = NULL;
        return (new);
    }
    for (; tab[len]; len++);
    new = malloc(sizeof(int *) * (len + 2));
    for (int i = 0; tab[i]; i++)
        new[i] = tab[i];
    new[len] = add;
    new[len + 1] = NULL;
    return (new);
}

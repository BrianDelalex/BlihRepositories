/*
** EPITECH PROJECT, 2019
** MyTeams
** File description:
** I have severe brain damage
*/

#include "utils/str_to_tab.h"

char **str_to_tab(char const *str)
{
    int j = 0, k = 0;
    char **tab = vmalloc(8 * strlen(str));

    while (*str) {
        tab[j] = vmalloc(strlen(str) + 1);
        while (*str && IS_EMPTY(*str))
            str++;
        if (!*str)
            break;
        while (*str && !IS_EMPTY(*str)) {
            tab[j][k] = *str;
            k++;
            str++;
        }
        tab[j][k] = 0x0;
        k = 0x0;
        j++;
    }
    tab[j] = NULL;
    return (tab);
}

void free_tab(char const **tab)
{
    for (int i = 0; tab[i]; i++)
        free((char *)tab[i]);
    free(tab);
}

int lentab(char const **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return (i);
}
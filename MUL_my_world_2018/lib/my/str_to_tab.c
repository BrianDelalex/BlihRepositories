/*
** EPITECH PROJECT, 2018
** str_to_tab.c
** File description:
** str_to_tab
*/

#include "../../include/my.h"

int chars_to_cut(char *str, int i, char cut)
{
    int y = i;
    int a = 0;

    for (; str[y] != cut && str[y] != '\0'; y++)
        a = a + 1;
    if (str[y] == '\0')
        return (-1);
    return (a + 2);
}

char **str_to_tab(char *str, char cut)
{
    char **tab = malloc(sizeof(char *) * (nbr_char_str(str, cut) + 1));
    int i = 0;
    int j = 0;
    int a = 0;

    for (; str[i] != '\0'; i++, j++) {
        tab[j] = malloc(sizeof(char) * chars_to_cut(str, i, cut));
        for (; str[i] != cut; i++, a++)
            tab[j][a] = str[i];
        tab[j][a] = '\0';
        a = 0;
    }
    free(str);
    return (tab);
}

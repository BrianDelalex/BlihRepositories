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

    for (; str[y] && str[y] != cut; y++)
        a = a + 1;
    return (a + 2);
}

char **str_to_tab(char *str, char cut)
{
    char **tab = malloc(sizeof(char *) * (nbr_char_str(str, cut) + 3));
    int i = 0;
    int j = 0;
    int a = 0;
    int alloc;

    for (; str[i] != '\0'; i++, j++) {
        alloc = chars_to_cut(str, i, cut) + 1;
        tab[j] = malloc(sizeof(char) * alloc);
        for(; str[i] && str[i] != cut; i++, a++)
            tab[j][a] = str[i];
        tab[j][a] = '\0';
        i = (str[i] == '\0') ? i - 1 : i;
        a = 0;
    }
    tab[j] = NULL;
    return (tab);
}

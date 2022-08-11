/*
** EPITECH PROJECT, 2019
** my_tab_to_str.c
** File description:
** transform a tab into str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_tab_to_str(char **tab, char c)
{
    char *str;
    int len = 0;
    int ct = 0;

    for (; tab[len]; len++);
    for (int i = 0; tab[i]; i++)
        len = len + my_strlen(tab[i]);
    str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++, ct++)
            str[ct] = tab[i][j];
        str[ct] = c;
        ct++;
    }
    str[len] = 0;
    return (str);
}

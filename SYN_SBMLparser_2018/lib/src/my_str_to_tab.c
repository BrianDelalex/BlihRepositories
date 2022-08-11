/*
** EPITECH PROJECT, 2019
** my_str_to_tab.c
** File description:
** cut a str at a given char and put it in char **
*/

#include <stdlib.h>

char **my_str_to_tab(char *str, char c)
{
    char **tab;
    int nb_line = 0, len = 0, index = 0, ct = 0;

    for (int i = 0; str[i]; i++)
        nb_line = str[i] == c ? nb_line + 1 : nb_line;
    if ((tab = malloc(sizeof(char *) * (nb_line + 2))) == NULL)
        return (NULL);
    while (index < nb_line + 1) {
        for (; str[len] && str[len] != c; len++);
        len = len - ct;
        if ((tab[index] = malloc(sizeof(char) * (len + 1))) == NULL)
            return (NULL);
        for (int i = 0; i < len && str[ct]; ct++, i++)
            tab[index][i] = str[ct];
        tab[index][len] = 0;
        ct = ct + 1;
        len = ct;
        index++;
    }
    tab[nb_line + 1] = NULL;
    return (tab);
}

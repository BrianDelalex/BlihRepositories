/*
** EPITECH PROJECT, 2019
** add_char_to_chartab.c
** File description:
** ads a char* to a char**
*/

#include <stdlib.h>

char **add_char_to_tab(char *str, char **str_tab)
{
    char **new_tab;
    int len = 0;
    int i = 0;

    if (str_tab == NULL) {
        str_tab = malloc(sizeof(char *) * 2);
        str_tab[0] = str;
        str_tab[1] = NULL;
        return (str_tab);
    }
    for (; str_tab[len]; len++);
    new_tab = malloc(sizeof(char *) * (len + 2));
    for (; str_tab[i]; i++)
        new_tab[i] = str_tab[i];
    new_tab[i] = str;
    new_tab[i + 1] = NULL;
    return (new_tab);
}

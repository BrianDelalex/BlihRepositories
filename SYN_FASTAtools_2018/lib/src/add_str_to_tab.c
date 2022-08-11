/*
** EPITECH PROJECT, 2019
** add_char_to_chartab.c
** File description:
** ads a char * to a char **
*/

#include <stdlib.h>

char **add_str_to_tab(char *str, char **str_tab)
{
    char **new_tab;
    int len = 0, i = 0;

    if (str == NULL)
        return (str_tab);
    if (str_tab == NULL) {
        new_tab = malloc(sizeof(char *) * 2);
        new_tab[0] = str;
        new_tab[1] = NULL;
        return (new_tab);
    }
    for (; str_tab[len]; len++);
    new_tab = malloc(sizeof(char *) * (len + 2));
    if (new_tab == NULL)
        return (NULL);
    for (; str_tab[i]; i++)
        new_tab[i] = str_tab[i];
    new_tab[i] = str;
    new_tab[i + 1] = NULL;
    free(str_tab);
    return (new_tab);
}

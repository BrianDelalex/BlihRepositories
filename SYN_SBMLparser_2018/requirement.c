/*
** EPITECH PROJECT, 2019
** requirement.c
** File description:
** return an array
*/

#include "include/requirement.h"
#include <stdlib.h>

char **my_str_to_word_array_synthesis(char const *str)
{
    char **tab;
    int nb_of_line = 0;
    int len = 0;
    int ct = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        if (IS_NON_ALPHANUMERIC(str[i]) && IS_NON_ALPHANUMERIC(str[i + 1]) == 0)
            nb_of_line = nb_of_line + 1;
    tab = malloc(sizeof(char *) * (nb_of_line + 2));
    for (int i = 0; str[i] && ct <= nb_of_line; i++, ct++) {
        for (; str[i] && IS_NON_ALPHANUMERIC(str[i]) == 1; i++);
        for (len = i; str[len] && IS_NON_ALPHANUMERIC(str[len]) == 0; len++);
        tab[ct] = malloc(sizeof(char) * ((len - i) + 1));
        for (len = 0; str[i] && IS_NON_ALPHANUMERIC(str[i]) == 0; i++, len++)
            tab[ct][len] = str[i];
        tab[ct][len] = 0;
    }
    tab[ct] = NULL;
    return (tab);
}

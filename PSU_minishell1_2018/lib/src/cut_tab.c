/*
** EPITECH PROJECT, 2019
** cut_tab.c
** File description:
** remove \t from str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *cut_tab(char *str)
{
    int i = 0;
    int len = 0;
    char *cut;

    for (; str[i] && str[i] == '\t'; i++);
    for (int j = i; str[j]; j++)
        if (str[j] != '\t' || ((str[j] == '\t' && str[j + 1] != '\t')
    && str[j + 1]))
            len = len + 1;
    cut = malloc(sizeof(char) * (len + 1));
    for (int j = 0; str[i]; i++, j++) {
        if ((str[i] == '\t' && str[i + 1] != '\t') && str[i + 1] != 0)
            cut[j] = 32;
        else if (str[i] != '\t')
            cut[j] = str[i];
        else
            j--;
    }
    cut[len] = 0;
    return (cut);
}

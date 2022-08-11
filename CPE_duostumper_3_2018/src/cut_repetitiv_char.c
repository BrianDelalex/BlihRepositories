/*
** EPITECH PROJECT, 2019
** cut_repetitiv_char.c
** File description:
** remove given char in a str
*/

#include <stdlib.h>

char *cut_repetitiv_char(char *str, char c)
{
    char *cut;
    int len = 0;
    int i = 0;
    int save_i = 0;

    for (; str[i] && (str[i] == c || str[i] == '\t'); i++);
    save_i = i;
    for (; str[i]; i++)
        if (str[i] != c || ((str[i] == c && str[i + 1] != c) && str[i + 1]))
            len = len + 1;
    cut = malloc(sizeof(char) * (len + 1));
    i = save_i;
    for (int j = 0; str[i]; i++)
        if (str[i] != c || ((str[i] == c && str[i + 1] != c) && str[i + 1])) {
            cut[j] = str[i];
            j++;
        }
    cut[len] = 0;
    return (cut);
}

/*
** EPITECH PROJECT, 2019
** cut_input_to_tab.c
** File description:
** cut the input into a tab
*/

#include <stdlib.h>

int count_lenght(char *input, int i, int *len, int *save)
{
    if (input[i] == 59 || input[i] == 124 || input[i] == 62 || input[i] == 60) {
        if ((input[i] == 60 && input[i + 1] == 60) ||
        (input[i] == 62 && input[i + 1] == 62))
             i++;
        *len = *len + 2;
        *save = *save + 2;
    }
    return (i);
}

void add_separator(char **tab, char *input, int *i, int ct)
{
    if (input[*i]) {
        tab[ct + 1] = malloc(sizeof(char) * 2);
        tab[ct + 1][0] = input[*i];
        tab[ct + 1][1] = 0;
    }
    if (input[*i + 1] && (input[*i + 1] == '<' || input[*i + 1] == '>')) {
        tab[ct + 1] = malloc(sizeof(char) * 3);
        tab[ct + 1][0] = input[*i];
        tab[ct + 1][1] = input[*i + 1];
        tab[ct + 1][2] = 0;
        *i = *i + 1;
    }
}

char **cut_input_to_tab(char *input)
{
    int len = 1, save = 1, ct = 0, j = 0;
    char **tab;

    for (int i = 0; input[i]; i++)
        i = count_lenght(input, i, &len, &save);
    tab = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; ct < save && input[i]; i++) {
        len = 0;
        for (;input[i + len] && input[i + len] != 59 && input[i + len] != 124
        && input[i + len] != 62 && input[i + len] != 60; len++);
        tab[ct] = malloc(sizeof(char) * (len + 2));
        for (; input[i] && input[i] != 59 && input[i] != 124 &&
        input[i] != 62 && input[i] != 60; i++, j++)
            tab[ct][j] = input[i];
        tab[ct][j] = 0;
        j = 0;
        add_separator(tab, input, &i, ct);
        ct = ct + 2;
    }
    tab[ct - 1] = NULL;
    return (tab);
}

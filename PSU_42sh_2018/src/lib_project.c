/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

int strncp(char *a, char *b, int n)
{
    int i = 0;

    for (; a[i] && b[i] && a[i] == b[i] && i != n; i++);
    if (i < n)
        return (-1);
    return (1);
}

char *strconcat(char *s1, char *s2)
{
    char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    int i = 0;

    for (; s1[i]; i++)
        new[i] = s1[i];
    for (int k = 0; s2[k]; k++, i++)
        new[i] = s2[k];
    new[i] = '\0';
    return (new);
}

int call_complete(char *str)
{
    struct stat s;

    if (stat(str, &s) == -1)
        return (-1);
    return (1);
}

int command_not_found(char *input)
{
    puterror(cut_arguments(input));
    puterror(": Command not found.\n");
    return (-1);
}

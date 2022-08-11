/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char *give_path(char **environ)
{
    int i;
    int k = 0;
    char *new;
    int j = 0;

    i = find_env(environ, "PWD=");
    if (i == -1)
        return("/Home/leo");
    new = malloc(sizeof(char) * (my_strlen(environ[i])));
    for (; environ[i][k]; k++)
        if (k > 0 && environ[i][k - 1] == '=')
            break;
    for (; environ[i][k]; k++, j++)
        new[j] = environ[i][k];
    new[j] = '\0';
    return (new);
}

int find_env(char **environ, char *name)
{
    int i = 0;

    for (; environ[i] && strncp(environ[i], name, my_strlen(name)) == -1; i++);
    if (environ[i] == NULL)
        return (-1);
    return (i);
}

int check_name(char *environ, char *name)
{
    int i = 0;

    for (; environ[i] && environ[i] != '=' && name[i]; i++)
        if (environ[i] != name[i])
            return (84);
    if (environ[i] != '=' && name[i] == '\0')
        return (84);
    return (0);
}

char **intra_unsetenv(char **environ, char *name)
{
    int i = 0;
    int k = 0;
    char **tab;

    for (; environ[i] && strncp(environ[i], name, my_strlen(name)) == -1; i++);
    if (environ[i] == NULL || check_name(environ[i], name) == 84)
        return (environ);
    tab = malloc(sizeof(char *) * (len_tab(environ) + 1));
    for (int j = 0; environ[j]; j++)
        if (j != i) {
            tab[k] = malloc(sizeof(char) * (my_strlen(environ[j]) + 1));
            my_strcpy(tab[k], environ[j]);
            k++;
        }
    tab[k] = NULL;
    return (tab);
}

char **my_unsetenv(char *input, char **environ)
{
    char **name = str_to_tab(input, ' ');

    for (int a = 0; name[a]; a++)
        environ = intra_unsetenv(environ, name[a]);
    for (int i = 0; name && name[i]; i++)
        free(name[i]);
    return (environ);
}

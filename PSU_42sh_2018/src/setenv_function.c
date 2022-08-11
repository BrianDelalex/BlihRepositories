/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char **my_setenv_more(char **tab, char *name, char *value)
{
    int i = 0, a = 0;

    for (; environ[i]; i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(environ[i]) + 1));
        my_strcpy(tab[i], environ[i]);
    }
    tab[i] = malloc(sizeof(char) * (my_strlen(name) + my_strlen(value) + 3));
    for (; name[a]; a++) {
        tab[i][a] = name[a];
        if (name[a + 1] == '\0')
            tab[i][a + 1] = '=';
    }
    a++;
    tab[i][a] = value[0] == '\0' ? '\0' : tab[i][a];
    for (int d = 0; value[d]; d++, a++) {
        tab[i][a] = value[d];
        if (value[d + 1] == '\0')
            tab[i][a + 1] = '\0';
    }
    tab[i + 1] = NULL;
    return (tab);
}

int error_management_setenv(char *name)
{
    for (int k = 0; name[k]; k++)
        if (name[k] != '_' && (((name[k] < 65 || name[k] > 90) && (name[k] < 97
    || name[k] > 122) && (name[k] < 48 || name[k] > 57)))) {
            puterror("setenv: Variable name must contain ");
            puterror("alphanumeric characters.\n");
            return (84);
        }
    return (0);
}

char *modify_existed_var(char *environ, char *value)
{
    char *new = malloc(sizeof(char) * (my_strlen(environ) +
my_strlen(value) + 1));
    int i = 0;
    int b = 0;

    for (; environ[i] && environ[i] != '='; i++, b++)
        new[b] = environ[i];
    new[b] = '=';
    b++;
    for (int k = 0; value[k]; k++, i++, b++)
        new[b] = value[k];
    new[b] = '\0';
    return (new);
}

char **my_setenv(char *input, char **environ)
{
    char **tab = malloc(sizeof(char *) * (len_tab(environ) + 2));
    char *name = cut_command(input);
    char *value = cut_command(name);
    int b = 0;

    for (; name[b] != '\0' && name[b] != ' '; b++);
    name[b] = '\0';
    if (error_management_setenv(name) == 84)
    return (environ);
    for (int i = 0; environ[i]; i++) {
        if (strncp(environ[i], name, my_strlen(name)) != -1) {
            environ[i] = modify_existed_var(environ[i], value);
            return (environ);
        }
    }
    tab = my_setenv_more(tab, name, value);
    free(name);
    free(value);
    return (tab);
}

/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

int check_f_d(char *inp)
{
    if (opendir(inp) == NULL) {
        puterror(inp);
        puterror(": Not a directory.\n");
        return (-1);
    }
    return (1);
}

char *cut_command(char *input)
{
    int a = 0;
    int b = 0;
    char *name = malloc(sizeof(char) * (my_strlen(input) + 2));

    for (; input[a] && input[a] != ' '; a++);
    a = (input[a]) ? a + 1 : a;
    for (; input[a]; a++, b++)
        name[b] = input[a];
    name[b] = '\0';
    return (name);
}

char **real_command(char *str)
{
    char **new = malloc(sizeof(char *) * (nbr_char_str(str, ' ') + 2));
    int k = 0;
    int j = 0;

    new[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            new[k][j] = '\0';
            k++;
            new[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
            j = 0;
        } else {
            new[k][j] = str[i];
            j++;
        }
    }
    new[k][j] = '\0';
    k++;
    new[k] = NULL;
    return (new);
}

int check_nbr_arg(char *str)
{
    int ret = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ')
            ret++;
    return (ret);
}

char *cut_path(char *path)
{
    int i = my_strlen(path) - 2;
    int k = 0;
    char *new = malloc(sizeof(char) * (i + 2));

    for (; path[i] && path[i] != '/'; i--);
    i++;
    for (; path[i]; i++, k++)
        new[k] = path[i];
    new[k] = '\0';
    return (new);
}

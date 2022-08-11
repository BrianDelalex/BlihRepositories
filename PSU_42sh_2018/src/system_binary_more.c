/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

int check_valid(char *path_binary, char **command)
{
    struct stat info;

    if (stat(path_binary, &info) == -1) {
        for (int i = 0; command[i]; i++) {
            puterror(command[i]);
            if (command[i + 1] != NULL)
                puterror(" ");
        }
        puterror(": Command not found.\n");
        for (int i = 0; command && command[i]; i++)
            free(command[i]);
        free(path_binary);
        return (84);
    }
    return (0);
}

char *find_bin(char **tmp, char *name)
{
    struct stat sta;
    char *s;
    int j = 0;

    for (int i = 0; tmp[i]; i++) {
        s = malloc(sizeof(char) * (my_strlen(tmp[i]) + my_strlen(name) + 2));
        for (; tmp[i][j]; j++)
            s[j] = tmp[i][j];
        s[j] = '/';
        j++;
        for (int k = 0; name[k]; k++, j++)
            s[j] = name[k];
        s[j] = '\0';
        if (stat(s, &sta) != -1)
            break;
        j = 0;
    }
    return (s);
}

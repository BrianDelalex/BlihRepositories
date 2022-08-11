/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char *cut_last_dir(char *path)
{
    int i = my_strlen(path) - 1;
    int k = 0;
    char *news = malloc(sizeof(char) * i);

    if (news == NULL)
        return (path);
    for (int slash = 1; i > 0 && slash > 0; i--) {
        if (path[i] == '/')
            slash--;
    }
    for (; k != i + 1; k++)
        news[k] = path[k];
    news[k] = '\0';
    return (news);
}

char *add_dir(char *path, char *new)
{
    char *npath = malloc(sizeof(char) * (my_strlen(path) + my_strlen(new) + 3));
    int i = 0;

    if (npath == NULL)
        return (path);
    for (; path[i]; i++)
        npath[i] = path[i];
    npath[i] = '/';
    i++;
    for (int k = 0; new[k]; i++, k++)
        npath[i] = new[k];
    npath[i] = '\0';
    return (npath);
}

char *change_env_pwd(char *path)
{
    char *env = malloc(sizeof(char) * 1024);
    int k = 4;

    if (env == NULL)
        return (path);
    env[0] = 'P';
    env[1] = 'W';
    env[2] = 'D';
    env[3] = '=';
    for (int i = 0; path[i] != '\0'; i++, k++)
        env[k] = path[i];
    env[k] = '\0';
    return (env);
}

char *change_path(char *dir, char *path)
{
    if (dir[0] == '.' && dir[1] == '.' && dir[2] == '\0') {
        if (nbr_char_str(path, '/') < 2) {
            puterror(dir);
            puterror(": No such file or directory.\n");
            return (path);
        }
        path = cut_last_dir(path);
    }
    else if (dir[0] != '.')
        path = add_dir(path, dir);
    return (path);
}

char *cd_function(char *input, char *path, char ***environ)
{
    int k = 0;
    struct stat s;
    char *new = cut_command(input), **dir_give = str_to_tab(new, '/');

    if (cd_option_more(environ, path, new) != NULL)
        return (give_path((*environ)));
    if (stat(new, &s) == -1 || check_dir(new) == 84) {
        puterror(new);
        puterror(": No such file or directory.\n");
        return (path);
    }
    if (check_f_d(new) == -1)
        return (path);
    for (int i = 0; dir_give[i]; i++) {
        path = change_path(dir_give[i], path);
        free(dir_give[i]);
    }
    for (; (*environ)[k] && strncp((*environ)[k], "PWD=", 3) == -1; k++);
    change_env_oldpwd(environ, k);
    (*environ)[k] = change_env_pwd(path);
    return (give_path((*environ)));
}

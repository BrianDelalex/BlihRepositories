/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char *go_home(char *new, char ***environ)
{
    int pwd = 0;
    int a = 4;

    for (; (*environ)[pwd] && strncp((*environ)[pwd], "PWD=", 3) == -1; pwd++);
    if ((*environ)[pwd] == NULL)
        return (new);
    change_env_oldpwd(environ, pwd);
    (*environ)[pwd] = malloc(sizeof(char) * 1024);
    (*environ)[pwd][0] = 'P';
    (*environ)[pwd][1] = 'W';
    (*environ)[pwd][2] = 'D';
    (*environ)[pwd][3] = '=';
    for (int i = 0; new[i]; i++, a++)
        (*environ)[pwd][a] = new[i];
    (*environ)[pwd][a] = '\0';
    return ((*environ)[pwd]);
}

int env_is_well(char *name, char ***environ)
{
    int i;

    i = find_env(*environ, name);
    if (i == -1 || ((*environ)[i] && (*environ)[i][4] == '\0'))
        return (-1);
    return (1);
}

char *norm_options_cd(char ***environ, char *path, char *new)
{
    struct stat s;

    if (my_strcmp("-", new) == 1 &&
unset_use_value("OLDPWD=", environ) == 0)
        return (oldpwd_path(path, environ));
    if (my_strcmp("-", new) == 1 &&
unset_use_value("OLDPWD=", environ) == -1)
        return (path);
    if (my_strcmp("/", new) == 1 && (stat(new, &s) != -1 &&
check_dir(new) != 84))
        return (go_home(new, environ));
    return (NULL);
}

char *cd_option_more(char ***environ, char *path, char *new)
{
    if (env_is_well("PWD=", environ) == -1)
        return (path);
    if (new[0] == '\0' && unset_use_value("HOME=", environ) == 0)
        return (cd_home(environ));
    else if (new[0] == '\0' && unset_use_value("HOME=", environ) == -1)
        return (path);
    return (norm_options_cd(environ, path, new));
}

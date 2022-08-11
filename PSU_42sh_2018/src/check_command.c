/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char *give_curent_dir(char ***environ)
{
    int pwd = 0;
    int i = 0;
    char *ret;

    for (; (*environ)[pwd] && strncp((*environ)[pwd], "PWD=", 3) == -1; pwd++);
    if ((*environ)[pwd] == NULL)
        return ("/home/leo");
    ret = malloc(sizeof(char) * my_strlen((*environ)[pwd]));
    for (int a = 4; (*environ)[pwd][a]; a++, i++)
        ret[i] = (*environ)[pwd][a];
    ret[i] = '\0';
    return (ret);
}

char *cut_arguments(char *input)
{
    int i = 0;
    char *s = malloc(sizeof(char) * (my_strlen(input) + 1));

    if (s == NULL)
        return (input);
    for (; input[i] && input[i] != ' '; i++)
        s[i] = input[i];
    s[i] = '\0';
    return (s);
}

int unset_use_value(char *name, char ***environ)
{
    int pwd = 0;

    for (; (*environ)[pwd]; pwd++) {
        if (strncp((*environ)[pwd], name, my_strlen(name) - 1) != -1)
            break;
    }
    if ((*environ)[pwd] == NULL)
        return (-1);
    return (0);
}

int check_command_more(char *input, char ***environ, pip_red_t *pr)
{
    if (my_strcmp(cut_arguments(input), "setenv") == 1) {
        if (check_nbr_arg(input) < 1) {
            puterror("unsetenv: Too few arguments.\n");
            return (1);
        }
        *environ = my_setenv(input, *environ);
        return (1);
    }
    if (my_strcmp(input, "env") == 1) {
        for (int i = 0; (*environ)[i]; i++)
            my_printf("%s\n", (*environ)[i]);
        return (1);
    }
    if (check_system_binary(input, environ, pr) == 1)
        return (1);
    return (0);
}

void check_command(char *input, char ***environ, pip_red_t *pr)
{
    if (my_strcmp(cut_arguments(input), "cd") == 1) {
        if (unset_use_value("PWD=", environ) == -1)
            return;
        cd_function(input, give_path(*environ), environ);
        chdir(give_curent_dir(environ));
        return;
    }
    if (my_strcmp(cut_arguments(input), "echo") == 1) {
        echo_function(input);
        return;
    }
    if (my_strcmp(cut_arguments(input), "unsetenv") == 1) {
        if (check_nbr_arg(input) < 1) {
            puterror("unsetenv: Too few arguments.\n");
            return;
        }
        *environ = my_unsetenv(input, *environ);
        return;
    }
    check_command_more(input, environ, pr);
}

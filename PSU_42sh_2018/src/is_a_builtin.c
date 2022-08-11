/*
** EPITECH PROJECT, 2019
** is_a_builtin.c
** File description:
** check if the command is a builtin
*/

#include "../include/my.h"

int cmp_redirection(char *inp, int nbr, int chev)
{
    int keep = nbr, i = 0x0, c = 0x0;

    for (; inp[i]; i++) {
        if (inp[i] == chev)
            nbr--;
        else
            nbr = keep;
        if (nbr == keep - 1 && inp[i - 1] != ' ')
            nbr = keep;
        if (inp[i] == '>' || inp[i] == '<')
            c++;
        if (inp[i] == '|' || c > 0x1)
            return (0x0);
        if (nbr == 0x0)
            break;
    }
    if (nbr == 0x0 && inp[i] && inp[i + 0x1] && inp[i + 0x1] != chev)
        return (0x1);
    return (0x0);
}

int red(char *inp, char ***environ, pip_red_t *pr)
{
    if (cmp_redirection(inp, 0x1, 0x3E) == 0x1) {
        redirections(inp, environ, 0x3E, pr);
        return (0x1);
    }
    if (cmp_redirection(inp, 0x2, 0x3E) == 0x1) {
        redirections(inp, environ, 124, pr);
        return (0x1);
    }
    if (cmp_redirection(inp, 0x1, 0x3C) == 0x1) {
        redirections(inp, environ, 0x3C, pr);
        return (0x1);
    }
    if (cmp_redirection(inp, 0x2, 0x3C) == 0x1) {
        redirections(inp, environ, 120, pr);
        return (0x1);
    }
    return (0x0);
}

void initialisation_struct(pip_red_t *pr)
{
    pr->pipe = 0x0;
    pr->red = 0x0;
    pr->chev = 0x0;
}

int is_a_builtin2(char *cmd, char **bin, char ***environ)
{
    if (my_strcmp(bin[0], "setenv")) {
        *environ = my_setenv(cmd, *environ);
        return (1);
    }
    if (my_strcmp(bin[0], "unsetenv")) {
        *environ = my_unsetenv(cmd, *environ);
        return (1);
    }
    if (my_strcmp(bin[0], "env")) {
        for (int i = 0; (*environ)[i]; i++)
            my_printf("%s\n", (*environ)[i]);
        return (1);
    }
    free(cmd);
    for (int i = 0; bin[i]; i++)
        free(bin[i]);
    free(bin);
    return (0);
}

int is_a_builtin(char *cmd, char ***environ)
{
    char *save = my_strdup(cmd);
    char **bin = cut_bin(cmd);
    int exit = check_exit(bin[0]);

    if (exit == 1) {
        return (-1);
        free(save);
        for (int i = 0; bin[i]; i++)
            free(bin[i]);
        free(bin);
    }
    if (my_strcmp(bin[0], "echo")) {
        exit = echo_function(cmd);
        return (exit);
    }
    if (my_strcmp(bin[0], "cd")) {
        cd_function(save, give_path(*environ), environ);
        chdir(give_curent_dir(environ));
        return (1);
    }
    return (is_a_builtin2(save, bin, environ));
}

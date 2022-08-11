/*
** EPITECH PROJECT, 2019
** find_function.c
** File description:
** finds entered function
*/

#include "minishell1.h"
#include <stdlib.h>

void exec_setenv(char ***environ, char *input)
{
    char *env = malloc(sizeof(char) * (my_strlen(input) - 3));
    int i = 6;
    int ct = 0;

    for (; input[i] == 32 && input[i]; i++);
    for (; input[i] != 32 && input[i]; i++, ct++)
        env[ct] = input[i];
    env[ct] = '=';
    ct++;
    for (; input[i] == 32 && input[i]; i++);
    for (; input[i]; i++, ct++)
        env[ct] = input[i];
    env[ct] = 0;
    *environ = add_char_to_tab(env, *environ);
}

void exec_unsetenv(char ***environ, char *input)
{
    int i = 0;
    int ct = 0;
    int size = 0;
    char *env;

    if (my_strlen(input) < 9)
        return;
    env = malloc(sizeof(char) * (my_strlen(input) - 8));
    for (int j = 9; input[j]; j++, ct++)
        env[ct] = input[j];
    env[ct] = 0;
    for (; (*environ)[i]; i++)
        if (my_strstr(env, (*environ)[i]) == 1)
            break;
    for (; (*environ)[size]; size++);
    if (i < size)
        *environ = remove_str_to_tab(*environ, i);
    free(env);
    if (my_strcmp("unsetenv *", input))
        *environ = NULL;
}

char *cut_cmd(char *input)
{
    char *cmd;
    int len = 0;

    for (; input[len] && input[len] != 32; len++);
    cmd = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        cmd[i] = input[i];
    cmd[len] = 0;
    return (cmd);
}

void find_function2(char *cmd, char *input, int i)
{
    int exec = 1;

    if (i == 5) {
        exec = exec_bin(environ, input);
        if (exec == 0)
            my_putstr(my_strconcat(cmd, ": Command not found.\n"));
    }
}

void find_function(t_ctrl *ctrl, char *input)
{
    int i = 0;
    char *cmd = cut_cmd(input);

    for (; ctrl->fctn[i]; i++) {
        if (my_strcmp(ctrl->fctn[i], cmd) == 1)
            break;
    }
    if (i == 0)
        my_puttab(environ);
    if (i == 1)
        exec_setenv(&environ, input);
    if (i == 2)
        exec_unsetenv(&environ, input);
    if (i == 3)
        exec_exit(ctrl);
    if (i == 4)
        exec_cd(&environ, input, ctrl);
    find_function2(cmd, input, i);
    free(input);
    free(cmd);
}

/*
** EPITECH PROJECT, 2019
** exec_env.c
** File description:
** exec env function
*/

#include "minishell1.h"
#include <stdlib.h>

void exec_unsetenv(char ***environ, char *input);

void exist_env_var(char ***environ, char *input)
{
    char **env;
    int len = 0;
    int i = 0;

    for (; (*environ)[len]; len++);
    env = malloc(sizeof(char *) * (len + 1));
    len = 0;
    for (; (*environ)[i]; i++) {
        for (;(*environ)[i][len] && (*environ)[i][len] != '='; len++);
        env[i] = malloc(sizeof(char) * (len + 1));
        len = 0;
        for (int j = 0; (*environ)[i][j] && (*environ)[i][j] != '='; j++)
            env[i][j] = (*environ)[i][j];
    }
    env[i] = NULL;
    for (int j = 0; env[j]; j++)
        if (my_strstr(env[j], (input + 7)) == 1)
            exec_unsetenv(environ, my_strconcat("unsetenv ", env[j]));
}

void exec_setenv(char ***environ, char *input)
{
    char *env = malloc(sizeof(char) * (my_strlen(input) - 3));
    int i = 6;
    int ct = 0;

    exist_env_var(environ, input);
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

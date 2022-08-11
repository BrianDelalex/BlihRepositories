/*
** EPITECH PROJECT, 2018
** env_var_exist.c
** File description:
** env_var_exist.c
*/

#include "my.h"

int var_cmp(char const *var, char *env)
{
    int i = 0;

    for (; var[i] && env[i] && env[i] != '=' && env[i] == var[i]; i++);
    if (env[i] == '=' && !var[i])
        return (1);
    return (0);
}

int env_var_exist(char **env, char const *var)
{
    int index = 0;

    for (; env[index]; index++)
        if (var_cmp(var, env[index]) == 1)
            return (index);
    return (-1);
}

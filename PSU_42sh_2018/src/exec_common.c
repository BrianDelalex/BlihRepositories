/*
** EPITECH PROJECT, 2019
** exec_common.c
** File description:
** common function to all exec mode
*/

#include "../include/my.h"

int check_stat(struct stat *st, char **path, char **env)
{
    char *path_ex, **ex;
    int i = 0, rtn = 0;

    i = env_var_exist(env, "PATH");
    if (i != -1) {
        path_ex = my_strdup(env[i] + 5);
        ex = str_to_tab(path_ex, ':');
    }
    *path = get_last_char_str(*path) == '/' ?
    remove_char_from_str(*path) : *path;
    rtn = stat(*path, st);
    if (rtn != 0 && i != -1) {
        for (int j = 0; ex[j] && rtn != 0; j++) {
            path_ex = my_strconcat(my_strconcat(ex[j], "/"), *path);
            rtn = stat(path_ex, st);
        }
        *path = path_ex;
    }
    return (rtn);
}

int check_exec_right(struct stat st, char *path)
{
    if (S_ISDIR(st.st_mode)) {
        my_putstr(my_strconcat(path, ": Permission denied.\n"));
        return (0);
    }
    return (1);
}

char **cut_bin(char *input)
{
    char **argv = str_to_tab(input, 32);

    return (argv);
}

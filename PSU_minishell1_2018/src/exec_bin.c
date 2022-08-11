/*
** EPITECH PROJECT, 2019
** exec_bin.c
** File description:
** execute binaries
*/

#include "minishell1.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

int check_exec_right(struct stat st, char *path)
{
    if (S_ISDIR(st.st_mode)) {
        my_putstr(my_strconcat(path, ": Command not found.\n"));
        return (0);
    }
    return (1);
}

char **cut_bin(char *input)
{
    char *cut_space = cut_repetitiv_char(input, 32);
    char **argv = my_str_to_tab(cut_space, 32);

    return (argv);
}

void open_process(char **argv, char **environ, char *path)
{
    pid_t cpid = fork();
    pid_t w;
    int wstatus;

    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0) {
        if (execve(path, argv, environ) == -1)
            perror(path);
        exit(0);
    }
    w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
    if (w == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
    if (wstatus == 11 || wstatus == 139)
        my_putstr("Segmentation fault\n");
}

int check_stat(struct stat *st, char **path, char **env)
{
    char *path_ex;
    char **ex;
    int i = 0, rtn = 0;

    for (; env[i] && my_strstr("PATH=", env[i]) != 1; i++);
    path_ex = malloc(sizeof(char) * (my_strlen(env[i]) - 4));
    for (int j = 0; env[i][j + 5]; j++)
        path_ex[j] = env[i][j + 5];
    path_ex[my_strlen(env[i]) - 5] = 0;
    ex = my_str_to_tab(path_ex, ':');
    *path = get_last_char_str(*path) == '/' ?
    remove_char_from_str(*path) : *path;
    rtn = stat(*path, st);
    if (rtn != 0) {
        for (int j = 0; ex[j] && rtn != 0; j++) {
            path_ex = my_strconcat(my_strconcat(ex[j], "/"), *path);
            rtn = stat(path_ex, st);
        }
        *path = path_ex;
    }
    return (rtn);
}

int exec_bin(char **environ, char *input)
{
    char *path = malloc(sizeof(char) * (my_strlen(input) + 1));
    char **argv = cut_bin(input);
    struct stat st;
    int rtn = 0;

    for (int i = 0; input[i] && input[i] != 32; i++)
        path[i] = input[i];
    path[my_strlen(input)] = 0;
    rtn = check_stat(&st, &path, environ);
    if (rtn == 0) {
        rtn = check_exec_right(st, path);
    } else
        return (0);
    if (rtn == 1) {
        open_process(argv, environ, path);
    }
    return (1);
}

/*
** EPITECH PROJECT, 2019
** exec_bin.c
** File description:
** execute binaries
*/

#include "../include/my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

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
    display_bin_error(wstatus);
}

int exec_bin(char **environ, char *input)
{
    char *path = my_strdup(input);
    char **argv = cut_bin(input);
    struct stat st;
    int rtn = 0;

    rtn = check_stat(&st, &(argv[0]), environ);
    if (rtn == 0) {
        rtn = check_exec_right(st, path);
    } else {
        my_printf("%s\n", strconcat(path, ": Command not found."));
    }
    if (rtn == 1) {
        open_process(argv, environ, argv[0]);
    }
    for (int i = 0; argv[i]; i++)
        free(argv[i]);
    free(argv);
    free(path);
    return (0);
}

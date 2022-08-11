/*
** EPITECH PROJECT, 2019
** exec_buffering_bin.c
** File description:
** buffering input until password is given to execute
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int exec_buff_bin(char **cmd, int pipefd[0])
{
    pid_t cpid = fork(), w;
    int wstatus;

    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0) {
        dup2(pipefd[0], 0);
        close(pipefd[1]);
        if (execve(cmd[0], cmd, environ) == -1)
            perror(cmd[0]);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
    if (w == -1)
        exit(EXIT_FAILURE);
    if (wstatus == 11 || wstatus == 139)
        my_putstr("Segmentation fault\n");
    return (0);
}

int exec_buffering_bin(char **input, int i)
{
    char **cmd = cut_bin(input[i]);
    char *pw = input[i + 2], *getline = NULL;
    struct stat st;
    int pipefd[2], rtn;
    char c = '\n';

    if (pipe(pipefd) == -1)
        return (-1);
    while ((getline == NULL || my_strstr2(getline, pw) != 1)) {
        getline = get_next_line(0);
        if (my_strstr2(getline, pw) == 1)
            break;
        write(pipefd[1], getline, my_strlen(getline));
        write(pipefd[1], &c, 1);
    }
    rtn = check_stat(&st, &cmd[0], environ);
    if (rtn == 0)
        rtn = check_exec_right(st, cmd[0]);
    if (rtn == 1)
        exec_buff_bin(cmd, pipefd);
    return (0);
}

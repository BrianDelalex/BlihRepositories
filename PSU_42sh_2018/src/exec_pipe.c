/*
** EPITECH PROJECT, 2019
** exec_pipe.c
** File description:
** exec two command separated by a pipe
*/

#include "../include/my.h"
#include <stdio.h>

void child_exec(int pipefd[2], char **cmd1, char **environ)
{
    dup2(pipefd[1], 1);
    close(pipefd[0]);
    if (execve(cmd1[0], cmd1, environ) == -1)
        perror(cmd1[0]);
}

int open_pipe_process(char **cmd1, char **cmd2, char **environ)
{
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1)
        perror("pipe");
    pid1 = fork();
    if (pid1 == 0) {
        child_exec(pipefd, cmd1, environ);
    } else {
        if ((pid2 = fork()) == 0) {
            dup2(pipefd[0], 0);
            close(pipefd[1]);
            if (execve(cmd2[0], cmd2, environ) == -1)
                perror(cmd2[0]);
        } else
            wait_return(pid1, cmd1[0]);
    }
    wait_and_close(pid2, cmd2[0], pipefd);
    return (0);
}

int exec_pipe(char **input, int i)
{
    char **cmd1 = cut_bin(input[i]);
    char **cmd2 = cut_bin(input[i + 2]);
    char *save1 = my_strdup(cmd1[0]), *save2 = my_strdup(cmd2[0]);
    int rtn1, rtn2;
    struct stat st1, st2;

    rtn1 = check_stat(&st1, &cmd1[0], environ);
    rtn2 = check_stat(&st2, &cmd2[0], environ);
    if (rtn1 == 0 && rtn2 == 0) {
        rtn1 = check_exec_right(st1, cmd1[0]);
        rtn2 = check_exec_right(st2, cmd2[0]);
    } else if (rtn1 == -1)
        my_printf("%s: Command not found.\n", save1);
    else
        my_printf("%s: Command not found.\n", save2);
    if (rtn1 == 1 && rtn2 == 1) {
        open_pipe_process(cmd1, cmd2, environ);
    }
    return (0);
}

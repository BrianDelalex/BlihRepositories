/*
** EPITECH PROJECT, 2019
** exec_and_redirect_in_file.c
** File description:
** execute the first command and redirect the output in a file
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int exec_child(char **cmd, int pipefd[2])
{
    dup2(pipefd[1], 1);
    close(pipefd[0]);
    if (execve(cmd[0], cmd, environ) == -1)
        perror(cmd[0]);
    exit(0);
}

int exec_and_redirect(char **cmd, int fd)
{
    int pipefd[2];
    pid_t pid1, pid2;
    char buff[1];

    if (pipe(pipefd) == -1)
        perror("pipe");
    pid1 = fork();
    if (pid1 == 0) {
        exec_child(cmd, pipefd);
    } else {
        if ((pid2 = fork()) == 0) {
            dup2(pipefd[0], 0);
            close(pipefd[1]);
            while (read(pipefd[0], buff, 1) != 0)
                write(fd, buff, 1);
            exit(0);
        }
    }
    return (0);
}

int exec_and_redirect_in_file(char **input, int i, int end)
{
    char **cmd = cut_bin(input[i]);
    int rtn;
    struct stat st;
    char *save = my_strdup(cmd[0]), buff[1];
    int fd = open(input[i + 2], O_RDWR | O_CREAT, S_IRWXU);

    if (fd == - 1)
        return (-1);
    if (end == 1)
        while (read(fd, buff, 1) != 0);
    rtn = check_stat(&st, &cmd[0], environ);
    if (rtn == 0)
        rtn = check_exec_right(st, cmd[0]);
    else
        my_printf("%s: Command not found.\n", save);
    if (rtn == 1)
        exec_and_redirect(cmd, fd);
    close(fd);
    return (0);
}

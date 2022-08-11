/*
** EPITECH PROJECT, 2019
** exec_with_modified_input.c
** File description:
** execute the bin with the input of the '< file'
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int exec_with_modified_input2(char **cmd, int fd)
{
    pid_t cpid, w;
    int wstatus;

    if ((cpid = fork()) == -1)
        return (-1);
    if (cpid == 0) {
        dup2(fd, 0);
        if (execve(cmd[0], cmd, environ) == -1)
            perror(cmd[0]);
    }
    w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
    if (w == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }
    if (wstatus == 11 || wstatus == 139)
        my_putstr("Segmentation fault\n");
    return (0);
}

int exec_with_modified_input(char **input_tab, int i)
{
    char **cmd = cut_bin(input_tab[i]);
    int fd = open(input_tab[i + 2], O_RDONLY), rtn;
    struct stat st;
    char *save = my_strdup(input_tab[i]);

    if (fd == -1) {
        my_printf("%s: No such file or directory.\n", input_tab[i + 2]);
        return (-1);
    }
    rtn = check_stat(&st, &cmd[0], environ);
    if (rtn == 0)
        rtn = check_exec_right(st, cmd[0]);
    else
        my_printf("%s: Command not found.\n", save);
    if (rtn == 1)
        exec_with_modified_input2(cmd, fd);
    close(fd);
    return (0);
}

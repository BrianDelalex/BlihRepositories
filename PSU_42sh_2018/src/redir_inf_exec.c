/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

void close_all(int *pfd, int fd)
{
    close(pfd[0x0]);
    close(pfd[0x1]);
    close(fd);
}

int read_on_file(char *file, pip_red_t *pr)
{
    int fd = open(file, O_RDONLY), rd;
    char *buff = malloc(sizeof(char) * 0x2);

    if (fd == -0x1) {
        puterror(file);
        puterror(": No such file or directory\n");
        return (-0x2);
    }
    while ((rd = read(fd, buff, 0x1)) != 0x0 && rd != -0x1)
        if (write(pr->pipefd[0x1], buff, 0X1) == -0x1)
            return (-0x1);
    free(buff);
    return (0x0);
}

int read_on_stdin(char *stop, pip_red_t *pr)
{
    char *buff, *new;
    int i = 0x0;

    while (0x2A) {
        my_putstr("> ");
        if ((buff = get_next_line(0x0)) == NULL)
            return (0x0);
        if (my_strcmp(buff, stop) == 0x1)
            return (0x0);
        new = malloc(sizeof(char) * (my_strlen(buff) + 2));
        for (i = 0x0; buff[i]; i++)
            new[i] = buff[i];
        buff[i] = 0xA;
        buff[i + 0x1] = 0x0;
        if (write(pr->pipefd[0x1], buff, my_strlen(buff)) == -0x1)
            return (-0x1);
        free(buff);
        free(new);
    }
    return (0x0);
}

void give_fd_bin(char **com, char ***env, pip_red_t *pr)
{
    if (com == NULL || pr->pid1 == -0x1)
        return;
    if ((pr->pid2 = fork()) == -0x1) {
        puterror("error fork!!\n");
        return;
    }
    if (pr->pid2 == 0x0) {
        close(pr->pipefd[0x1]);
        dup2(pr->pipefd[0x0], 0x0);
        if (execve(com[0x0], com, *env) == -0x1) {
            puterror("Execve error\n");
            exit(0x0);
        }
        exit(0x0);
    }
    close(pr->pipefd[0x0]);
    close(pr->pipefd[0x1]);
}

void exec_inf(char **com, char ***env, char *file, pip_red_t *pr)
{
    int ret = 0x0;

    if (pr->chev == 0x3C * 0x2) {
        if (read_on_stdin(file, pr) == -0x1)
            return;
        give_fd_bin(com, env, pr);
        return;
    }
    if ((pr->pid1 = fork()) == -0x1)
        puterror("error fork!!\n");
    if (pr->pid1 == 0x0) {
        close(pr->pipefd[0x0]);
        dup2(pr->pipefd[0x1], 0x1);
        if ((ret = read_on_file(file, pr)) == 0x0)
            exit(0x0);
        exit(0x0);
    }
    give_fd_bin(com, env, pr);
}

/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char **cut_chevrons(char *inp, int chev)
{
    char **tab = malloc(sizeof(char *) * 0x3);
    int i = 0x0, k = 0x0;

    if (chev > 62)
        chev = chev / 0x2;
    tab[0x0] = malloc(sizeof(char) * my_strlen(inp));
    for (; inp[i] && inp[i] != chev; i++)
        tab[0x0][i] = inp[i];
    tab[0x0][i] = 0x0;
    tab[0x0] = regex_space(tab[0x0]);
    for (; inp[i] == chev; i++);
    tab[0x1] = malloc(sizeof(char) * my_strlen(inp));
    for (; inp[i] && inp[i] != 0x3C && inp[i] != 0x3E &&
inp[i] != 0x3C * 0X2 && inp[i] != 0x3E * 0X2; i++, k++)
        tab[0x1][k] = inp[i];
    tab[0x1][k] = 0x0;
    tab[0x1] = regex_space(tab[0x1]);
    tab[0x2] = NULL;
    return (tab);
}

void write_in_file(char *file, pip_red_t *pr)
{
    int fd = open(file, O_RDWR), rd;
    char *buff = malloc(sizeof(char) * 0x2);

    if (fd == -0x1)
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd == -0x1)
        return;
    if ((pr->pid2 = fork()) == 0x0) {
        close(fd);
        wait_return(pr->pid2, file);
        return;
    }
    if (pr->chev > 0x3E)
        while ((rd = read(fd, buff, 0x1)) != 0x0 && rd != -0x1);
    close(pr->pipefd[0x1]);
    dup2(pr->pipefd[0x0], 0x0);
    while ((rd = read(pr->pipefd[0x0], buff, 0x1)) != -0x1 && rd != 0x0)
        if (write(fd, buff, 0x1) == -0x1)
            break;
    close_all(pr->pipefd, fd);
    exit(0);
}

void exec_sup(char **com, char ***env, char *file, pip_red_t *pr)
{
    if (com == NULL)
        return;
    if ((pr->pid1 = fork()) == -0x1) {
        puterror("error fork!!\n");
        return;
    }
    if (pr->pid1 == 0x0) {
        close(pr->pipefd[0x0]);
        dup2(pr->pipefd[0x1], 0x1);
        if (execve(com[0x0], com, *env) == -0x1) {
            puterror("Execve error\n");
            exit(0);
        }
    } else {
        wait_return(pr->pid1, com[0x0]);
        write_in_file(file, pr);
    }
}

int redirections_exec(char **com, char ***environ, char *bin, pip_red_t *pr)
{
    static char **com1 = NULL, *bin1 = NULL;

    if (com != NULL) {
        com1 = com;
        com1[0x0] = bin;
    } else
        bin1 = bin;
    if (pr->red == 0x2) {
        if (pipe(pr->pipefd) == -0x1) {
            puterror("Pipe can't be create\n");
            return (-0x1);
        }
        if (pr->chev == 0x3E || pr->chev == 0x3E * 0x2)
            exec_sup(com1, environ, bin1, pr);
        if (pr->chev == 0x3C || pr->chev == 0x3C * 0x2)
            exec_inf(com1, environ, bin1, pr);
    }
    return (0x0);
}

void redirections(char *inp, char ***environ, int chev, pip_red_t *pr)
{
    char **split = cut_chevrons(inp, chev);

    pr->pipe = 0x0;
    pr->red = 0x1;
    pr->chev = chev;
    check_system_binary(split[0x0], environ, pr);
    pr->red = 0x2;
    check_system_binary(split[0x1], environ, pr);
    free_tab(split);
}

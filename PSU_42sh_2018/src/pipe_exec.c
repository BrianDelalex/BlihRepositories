/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

int pipe_w_builtin(char *a)
{
    if (my_strcmp(cut_arguments(a), "setenv") == 0x1)
        return (0x1);
    if (my_strcmp(cut_arguments(a), "unsetenv") == 0x1)
        return (0x1);
    return (0x0);
}

void wait_and_close(pid_t pid, char *bin, int *fd)
{
    close(fd[0]);
    close(fd[1]);
    wait_return(pid, bin);
}

int execpipe(char **argv1, char **argv2, pip_red_t *pip, char ***env)
{
    if ((pip->pid1 = fork()) == -0x1) {
        puterror("error fork!\n");
        return (0x1);
    }
    if (pip->pid1 == 0x0) {
        close(pip->pipefd[0x0]);
        dup2(pip->pipefd[0x1], 0x1);
        if (execve(argv1[0x0], argv1, *env) == -0x1)
            puterror("Execve error\n");
    } else {
        if ((pip->pid2 = fork()) == 0x0) {
            close(pip->pipefd[0x1]);
            dup2(pip->pipefd[0x0], 0x0);
            if (execve(argv2[0x0], argv2, *env) == -0x1)
                puterror("Execve error\n");
        }
        wait_return(pip->pid1, argv1[0x0]);
    }
    wait_and_close(pip->pid2, argv2[0x0], pip->pipefd);
    return (0x0);
}

int exec_with_pipe(char *path_binary, char ***env, char **com, pip_red_t *pip)
{
    static char **com1;

    if (pip->pipe == 0x1) {
        com1 = com;
        com1[0x0] = path_binary;
    }
    else {
        com[0x0] = path_binary;
        if (pipe(pip->pipefd) == -0x1) {
            puterror("Pipe can't be create\n");
            return (-0x1);
        }
        execpipe(com1, com, pip, env);
        free_tab(com1);
        free_tab(com);
    }
    return (0x0);
}

void pipe_exec(char *com, char ***environ, pip_red_t *pip)
{
    char **split = str_to_tab(com, '|');

    pip->pipe = 0x1;
    for (int i = 0x0; split[i]; i++)
        split[i] = regex_space(split[i]);
    for (int i = 0x0; split[i] && i != 0x2; i++) {
        if (pipe_w_builtin(split[i]) == 0x1)
            return;
        check_system_binary(split[i], environ, pip);
        pip->pipe = 0x2;
    }
    pip->pipe = 0x0;
}

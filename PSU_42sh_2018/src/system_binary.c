/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char *binary_system(char *str, char ***environ, int pa)
{
    char **tmp, *ret;
    char *path_env = malloc(sizeof(char) * my_strlen((*environ)[pa]));

    str = cut_arguments(str);
    if (call_complete(str) == 1 || (*environ)[pa] == NULL)
        return (str);
    for (int i = 5, k = 0; (*environ)[pa][i]; i++, k++) {
        path_env[k] = (*environ)[pa][i];
        if ((*environ)[pa][i + 1] == '\0')
            path_env[k + 1] = '\0';
    }
    tmp = str_to_tab(path_env, ':');
    free(path_env);
    ret = find_bin(tmp, str);
    for (int i = 0; tmp && tmp[i]; i++)
        free(tmp[i]);
    if (str[0] == '.' || str[0] == '/')
        return (str);
    return (ret);
}

void wait_return(int pid, char *path_binary)
{
    int status, s;

    s = waitpid(pid, &status, WUNTRACED | WCONTINUED);
    if (s == -1)
        return;
    if (status != 0 && status != 139 && status != 11 && status != 13
&& status != 8 && status != 136) {
        puterror(path_binary);
        puterror(": Exec format error. Wrong Architecture.\n");
    }
    if (WCOREDUMP(status) && (status == 139 || status == 11))
        puterror("Segmentation fault (core dump)\n");
    if ((status == 139 || status == 11) && !WCOREDUMP(status) )
        puterror("Segmentation fault\n");
    if ((status == 8 || status == 136) && WCOREDUMP(status))
        puterror("Floating exception (core dump)\n");
    if ((status == 8 || status == 136) && !WCOREDUMP(status))
        puterror("Floating exception\n");
}

pid_t check_more_bin(char *path_binary, char ***environ, char **com)
{
    pid_t pid;

    if ((pid = fork()) == -1) {
        puterror("Processus can't be create\n");
        return (pid);
    } else if (pid == 0) {
        if (execve(path_binary, com, *environ) == -1) {
            perror(path_binary);
            kill(getpid(), SIGKILL);
        }
        return (pid);
    }
    return (pid);
}

int pipe_and_red(char *path_binary, char ***env, char **com, pip_red_t *pr)
{
    if (pr->pipe == 0x1 || pr->pipe == 0x2) {
        exec_with_pipe(path_binary, env, com, pr);
        return (0x1);
    }
    if (pr->red == 0x1) {
        redirections_exec(com, env, path_binary, pr);
        return (0x1);
    }
    return (0x0);
}

int check_system_binary(char *input, char ***env, pip_red_t *pr)
{
    int a = 0x0;
    pid_t pid;
    char *path_binary, **com;

    if (pr->red == 0x2)
        return (redirections_exec(NULL, env, input, pr));
    if (call_complete(cut_arguments(input)) != 1) {
        for (; (*env)[a] && strncp((*env)[a], "PATH=", 5) == -1; a++);
        if ((*env)[a] == NULL || ((*env)[a] && (*env)[a][5] == '\0'))
            return (command_not_found(input));
    }
    path_binary = binary_system(input, env, a);
    com = real_command(input);
    if (check_valid(path_binary, com) == 0x54)
        return (0x0);
    if (pipe_and_red(path_binary, env, com, pr) == 1)
        return (0x1);
    pid = check_more_bin(path_binary, env, com);
    wait_return(pid, path_binary);
    return (0x1);
}

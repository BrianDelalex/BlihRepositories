/*
** EPITECH PROJECT, 2019
** requirement.c
** File description:
** my_ps_synthesis
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void  my_ps_synthesis(void)
{
    pid_t pid = fork(), w;
    int wstatus;
    char *ps[2] = {"ps", NULL};

    if (pid == -1)
        return;
    if (pid == 0) {
        if (execve("/usr/bin/ps", ps, environ) == -1)
            return;
    }
    if (pid != 0) {
        w = waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
        if (w == -1)
            return;
    }
}

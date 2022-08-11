/*
** EPITECH PROJECT, 2019
** exec_exit.c
** File description:
** execute exit function
*/

#include "minishell1.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void exec_exit(t_ctrl *ctrl)
{
    free_values(ctrl);
    my_putstr("exit\n");
    exit(0);
}

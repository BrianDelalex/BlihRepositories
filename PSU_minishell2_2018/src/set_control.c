/*
** EPITECH PROJECT, 2019
** set_control.c
** File description:
** set struct control
*/

#include "minishell1.h"
#include <stdlib.h>

t_ctrl *set_control(void)
{
    t_ctrl *ctrl = malloc(sizeof(t_ctrl));
    int i_pwd = 0;

    for (; environ[i_pwd] && my_strstr("PWD", environ[i_pwd]) != 1; i_pwd++);
    ctrl->pwd = malloc(sizeof(char) * (my_strlen(environ[i_pwd]) - 3));
    for (int i = 0; environ[i_pwd][i + 4]; i++)
        ctrl->pwd[i] = environ[i_pwd][i + 4];
    ctrl->pwd[my_strlen(environ[i_pwd]) - 4] = 0;
    ctrl->fctn = malloc(sizeof(char *) * 6);
    ctrl->fctn[0] = "env";
    ctrl->fctn[1] = "setenv";
    ctrl->fctn[2] = "unsetenv";
    ctrl->fctn[3] = "exit";
    ctrl->fctn[4] = "cd";
    ctrl->fctn[5] = NULL;
    ctrl->redirect = 0;
    return (ctrl);
}

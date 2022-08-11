/*
** EPITECH PROJECT, 2019
** set_control.c
** File description:
** set the control struct
*/

#include "../include/my.h"

int free_control(control_t *ctrl)
{
    int rtn = ctrl->rtn;

    free(ctrl);
    return (rtn);
}

control_t *set_control(void)
{
    control_t *ctrl = malloc(sizeof(control_t));

    ctrl->redirect = -1;
    ctrl->rtn = -1;
    return (ctrl);
}

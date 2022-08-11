/*
** EPITECH PROJECT, 2019
** free_values.c
** File description:
** frees memorie before stoping programm
*/

#include "minishell1.h"
#include <stdlib.h>

void free_values(t_ctrl *ctrl)
{
    free(ctrl->fctn);
}

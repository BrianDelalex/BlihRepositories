/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parses 104intersection input
*/

#include "my.h"
#include <stdlib.h>

t_control *parsing(char **av)
{
    t_control *ctrl = malloc(sizeof(t_control));

    ctrl->shape = my_getnbr(av[1]);
    if (ctrl->shape == 0)
        exit(84);
    ctrl->pt = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i++)
        ctrl->pt[i] = my_getnbr(av[i + 2]);
    ctrl->dir = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i++)
        ctrl->dir[i] = my_getnbr(av[i + 5]);
    ctrl->param = my_getnbr(av[8]);
    return (ctrl);
}

/*
** EPITECH PROJECT, 2018
** display_info.c
** File description:
** displays infos
*/

#include "my.h"
#include <stdio.h>

void display_info(t_control *ctrl)
{
    if (ctrl->shape == 1)
        printf("Sphere of radius %d\n", ctrl->param);
    else if (ctrl->shape == 2)
        printf("Cylinder of radius %d\n", ctrl->param);
    else
        printf("Cone with a %d degree angle\n", ctrl->param);
    printf("Line passing through the point (%.0f, %.0f, %.0f) ", ctrl->pt[0],
     ctrl->pt[1], ctrl->pt[2]);
    printf("and parallel to the vector (%.0f, %.0f, %.0f)\n", ctrl->dir[0],
     ctrl->dir[1], ctrl->dir[2]);
}

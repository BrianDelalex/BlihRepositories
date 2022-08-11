/*
** EPITECH PROJECT, 2018
** ckeck_intersection_cone.c
** File description:
** checks if line passes trought the cone
*/

#include "my.h"
#include <math.h>
#include <stdio.h>

void check_intersection_cone(t_control *ctrl)
{
    float a = (float) pow(ctrl->dir[0], 2) + pow(ctrl->dir[1], 2) -
     (pow(ctrl->dir[2], 2) * pow(tan((float)ctrl->param * M_PI / 180), 2));
    float c = (float) pow(ctrl->pt[0], 2) + pow(ctrl->pt[1], 2) -
     (pow(ctrl->pt[2], 2) * pow(tan((float) ctrl->param * M_PI / 180), 2));
    float b = (float) (2 * ctrl->dir[0] * ctrl->pt[0]) +
     (2 * ctrl->dir[1] * ctrl->pt[1]) - (2 * ctrl->dir[2] * ctrl->pt[2] *
      pow(tan((float) ctrl->param * M_PI / 180), 2));

    ctrl->delta = (float) pow(b, 2) - 4 * a * c;
    if (a == 0)
        ctrl->delta = -1;
    if (ctrl->delta > 0) {
        ctrl->t1 = (float) ((-b) + sqrt(ctrl->delta)) / (2 * a);
        ctrl->t2 = (float) ((-b) - sqrt(ctrl->delta)) / (2 * a);
    } else if (ctrl->delta == 0)
        ctrl->t1 = (float) (-b) / (2 * a);
    calcul_intersection_pos(ctrl);
}

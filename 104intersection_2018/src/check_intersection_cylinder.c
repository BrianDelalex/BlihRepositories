/*
** EPITECH PROJECT, 2018
** check_intersection_cylinder.c
** File description:
** check if the line pass trought cylinger
*/

#include "my.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void calcul_intersection_pos_cylinder(t_control *ctrl)
{
    if (ctrl->dir[0] == 0 && ctrl->dir[1] == 0) {
        printf("There is an infinite number of intersection points.\n");
        exit(0);
    }
    if (ctrl->delta > 0) {
        ctrl->x1 = malloc(sizeof(float) * 3);
        for (int i = 0; i < 3; i++)
            ctrl->x1[i] = ctrl->dir[i] * ctrl->t1 + ctrl->pt[i];
        ctrl->x2 = malloc(sizeof(float) * 3);
        for (int i = 0; i < 3; i++)
            ctrl->x2[i] = ctrl->dir[i] * ctrl->t2 + ctrl->pt[i];
    } else if (ctrl->delta == 0) {
        ctrl->x1 = malloc(sizeof(float) * 3);
        for (int i = 0; i < 3; i++)
            ctrl->x1[i] = ctrl->dir[i] * ctrl->t1 + ctrl->pt[i];
    }
    display_sphere_intersection(ctrl);
}

void check_intersection_cylinder(t_control *ctrl)
{
    int a = pow(ctrl->dir[0], 2) + pow(ctrl->dir[1], 2);
    int b = 2 * ctrl->dir[0] * ctrl->pt[0] + 2 * ctrl->dir[1] * ctrl->pt[1];
    int c = pow(ctrl->pt[0], 2) + pow(ctrl->pt[1], 2) - pow(ctrl->param, 2);

    ctrl->delta = pow(b, 2) - 4 * a * c;
    if (a == 0)
        ctrl->delta = -1;
    if (ctrl->delta > 0) {
        ctrl->t1 = (float) (((-b) + sqrt(ctrl->delta)) / (2 * a));
        ctrl->t2 = (float) (((-b) - sqrt(ctrl->delta)) / (2 * a));
    } else if (ctrl->delta == 0)
        ctrl->t1 = (float) (-b) / (2 * a);
    calcul_intersection_pos_cylinder(ctrl);
}

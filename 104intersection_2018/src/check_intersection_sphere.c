/*
** EPITECH PROJECT, 2018
** check_intersection_sphere.c
** File description:
** checks if the line passes trought the sphere
*/

#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void display_sphere_intersection(t_control *ctrl)
{
    if (ctrl->dir[0] == 0 && ctrl->dir[1] == 0 && ctrl->shape == 3)
        if (ctrl->pt[0] == 0 && ctrl->pt[1] == 0) {
            printf("There is an infinite number of intersection points.\n");
            exit(0);
        }
    if (ctrl->delta > 0) {
        printf("2 intersections points:\n");
        printf("(%.3f, %.3f, %.3f)\n", ctrl->x1[0], ctrl->x1[1], ctrl->x1[2]);
        printf("(%.3f, %.3f, %.3f)\n", ctrl->x2[0], ctrl->x2[1], ctrl->x2[2]);
    } else if (ctrl->delta == 0) {
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", ctrl->x1[0], ctrl->x1[1], ctrl->x1[2]);
    } else
        printf("No intersection point.\n");
}

void calcul_intersection_pos(t_control *ctrl)
{
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

void check_intersection_sphere(t_control *ctrl)
{
    int a = pow(ctrl->dir[0], 2) + pow(ctrl->dir[1], 2) + pow(ctrl->dir[2], 2);
    int c = pow(ctrl->pt[0], 2) + pow(ctrl->pt[1], 2) + pow(ctrl->pt[2], 2)
     - pow(ctrl->param, 2);
     int b = (2 * ctrl->dir[0] * ctrl->pt[0]) + (2 * ctrl->dir[1] * ctrl->pt[1])
      + (2 * ctrl->dir[2] * ctrl->pt[2]);
    ctrl->delta = pow(b, 2) - 4 * a * c;
    if (ctrl->delta > 0) {
        ctrl->t1 = (float) ((-b) + sqrt(ctrl->delta)) / (2 * a);
        ctrl->t2 = (float) ((-b) - sqrt(ctrl->delta)) / (2 * a);
    } else if (ctrl->delta == 0)
        ctrl->t1 = (float) (-b) / (2 * a);
    calcul_intersection_pos(ctrl);
}

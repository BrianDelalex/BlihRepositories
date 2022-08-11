/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for 104intersection project
*/

#include "my.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_control *ctrl;
    handle_errors(ac, av);
    ctrl = parsing(av);
    display_info(ctrl);
    if (ctrl->shape == 1)
        check_intersection_sphere(ctrl);
    else if (ctrl->shape == 2)
        check_intersection_cylinder(ctrl);
    else
        check_intersection_cone(ctrl);
    return (0);
}

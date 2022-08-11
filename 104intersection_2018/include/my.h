/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes of function for 104intersection
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

int handle_errors(int ac, char **av);
int my_puterror(char const *str);
int my_getnbr(char const *str);
t_control *parsing(char **av);
void check_intersection_sphere(t_control *ctrl);
void display_info(t_control *ctrl);
void calcul_intersection_pos(t_control *ctrl);
void check_intersection_cylinder(t_control *ctrl);
void display_sphere_intersection(t_control *ctrl);
void check_intersection_cone(t_control *ctrl);

#endif

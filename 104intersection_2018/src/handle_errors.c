/*
** EPITECH PROJECT, 2018
** handle_errors.c
** File description:
** handles input errors of 104intersection
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int check_input(char **av, int i)
{
    for (int j = 0; av[i][j]; j++)
        if ((av[i][j] < 48 || av[i][j] > 57) && av[i][j] != '-') {
            my_puterror("Unknow arguments\n");
            exit(84);
        }
    return (0);
}

void print_usage(void)
{
    printf("USAGE\n    ");
    printf("./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n    ");
    printf("opt            surface option: 1 for a sphere, 2 for a cylinder");
    printf(", 3 for a cone\n    ");
    printf("(xp, yp, zp)   coordinates of a point by which the light ray");
    printf(" passes through\n    ");
    printf("(xv, yv, zv)   coordinates of a vector parallel to the light ray");
    printf("\n    ");
    printf("p              parameter: radius of the sphere, radius of the");
    printf("cylinder, or\n    ");
    printf("               angle formed by the cone and the Z-axis\n");
}

int handle_errors(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage();
        exit(0);
    }
    if (ac < 9) {
        my_puterror("Not enought arguments\n");
        exit(84);
    } else if (ac > 9) {
        my_puterror("Too much arguments\n");
        exit(84);
    }
    for (int i = 1; i < ac; i++)
        check_input(av, i);
    if (my_getnbr(av[1]) != 1 && my_getnbr(av[1]) != 2 &&
     my_getnbr(av[1]) != 3) {
         my_puterror("Unknow shape\n");
         exit(84);
     }
    return (0);
}

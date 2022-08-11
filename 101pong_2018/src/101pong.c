/*
** EPITECH PROJECT, 2018
** 101pong.c
** File description:
** 101pong main fuctions
*/

#include "my.h"
#include <stdlib.h>

int check_number_of_arg(int ac, char **av)
{
    if (ac < 8) {
        my_puterror("Too few arguments");
        exit (84);
    } else if (ac > 8) {
        my_puterror("Too much arguments");
        exit(84);
    } else
        return (0);
}

int main(int ac, char **av)
{
    check_number_of_arg(ac, av);
    calcul_velocity(av);
}

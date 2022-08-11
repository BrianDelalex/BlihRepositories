/*
** EPITECH PROJECT, 2019
** handle_errors.c
** File description:
** handles errors of matchstick input
*/

#include "matchstick.h"

int handle_errors(int ac, char **av)
{
    if (ac < 3) {
        my_puterror("Too few arguments\n");
        return (84);
    } else if (ac > 3) {
        my_puterror("Too much arguments\n");
        return (84);
    }
    for (int i = 0; av[1][i]; i++)
        if (av[1][i] < 48 || av[1][i] > 57) {
            my_puterror("Arguments must be positive numbers\n");
            return (84);
        }
    for (int i = 0; av[2][i]; i++)
        if (av[2][i] < 48 || av[2][i] > 57) {
            my_puterror("Arguments must be positive numbers\n");
            return (84);
        }
    return (0);
}

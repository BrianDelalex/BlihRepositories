/*
** EPITECH PROJECT, 2018
** find_previous_flag_index.c
** File description:
** finds and returns the previous flags index
*/

#include "my.h"

int look_for_flag(int ct, char **av)
{
    switch (av[ct][1]) {
        case 't':
        case 's':
        case 'r':
        case 'z':
            return (1);
        default:
            return (0);
    }
}

int find_previous_flag_index(char **av, int ct)
{
    int i = 2;

    for (; ct > 1; ct--) {
        if (my_strlen(av[ct]) == 2) {
            i = look_for_flag(ct, av);
        }
        if (i == 1)
            return (ct);
    }
}

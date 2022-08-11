/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for BSQ project
*/

#include "my.h"
#include <stdlib.h>
#include "struct.h"

int main(int ac, char **av)
{
    map_t map;

    if (ac == 1) {
        my_puterror("Too few arguments");
        exit(84);
    } else if (ac != 2) {
        my_puterror("Too much arguments");
        exit (84);
    }
    map = create_map(av[1]);
    bsq(map);
    return (0);
}

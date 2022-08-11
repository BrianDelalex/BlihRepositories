/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for sokoban project
*/

#include "my.h"
#include <stdlib.h>
#include "struct.h"

int main(int ac, char **av)
{
    t_map map;

    if (ac < 2) {
        my_puterror("Too few arguments\n");
        exit(84);
    } else if (ac > 2) {
        my_puterror("Too much arguments\n");
        exit(84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n     ./my_sokoban map\nDescription\n     ");
        my_putstr("map file representing the warehouse map, containing");
        my_putstr(" ‘#’ for walls,\n         ‘P’ for the player");
        my_putstr(", ‘X’ for boxes and ‘O’ for storage locations.\n");
        return (0);
    }
    check_map(av[1]);
    map = create_map(av[1]);
    display_map(map);
    return (0);
}

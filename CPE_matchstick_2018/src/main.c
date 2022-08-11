/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for matchstick project
*/

#include "matchstick.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    t_map *map;
    int winner = 0;

    if (handle_errors(ac, av) == 84)
        return (84);
    map = create_map(av);
    winner = chose_turn(map);
    free_values(map);
    if (winner == 84)
        return (0);
    if (winner == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    if (winner == 0){
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
}

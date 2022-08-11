/*
** EPITECH PROJECT, 2019
** search_exit.c
** File description:
** look for an exit in the maze
*/

#include "solver.h"

int search_exit(char **map)
{
    int size[2];

    size[0] = my_strlen(map[0]);
    size[1] = 0;
    for (; map[size[1]]; size[1] = size[1] + 1);
    if (map[0][0] == 'X' || map[size[1] - 1][size[0] - 2] == 'X') {
        my_printf("no solution found\n");
        exit(0);
    }
    return (0);
}

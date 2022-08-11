/*
** EPITECH PROJECT, 2018
** is_square_of_size.c
** File description:
** return 1 if a square of the given size can be found at the right pos
*/

#include "my.h"

int look_for_obstacle(int *j, int col_max, int i, map_t map)
{
    for (;*j < col_max && *j < map.col; *j = *j + 1) {
        if (map.map[i][*j] == 'o')
            return (0);
    }
    return (1);
}

int is_square_of_size(map_t map, int row, int col, int square_size)
{
    int i = row;
    int j = col;
    int col_max = square_size + col;

    for (; i < (row + square_size) && i <= map.lines; i++) {
        j = col;
        if (look_for_obstacle(&j, col_max, i, map) == 0)
            return (0);
    }
    if (i - row == square_size && j - col == square_size)
        return (1);
    return (0);
}
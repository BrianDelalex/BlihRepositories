/*
** EPITECH PROJECT, 2018
** find_biggest_square.c
** File description:
** find the bigger square at the given pos
*/

#include "my.h"

int find_biggest_square(map_t map, int row, int col)
{
    int i = 0;

    for (i = col; map.map[row][i] != 'o' && i < map.col; i++);
    while (is_square_of_size(map, row, col, i - col) != 1 && (i - col) != 0)
        i = i - 1;
    return (i - col);
}
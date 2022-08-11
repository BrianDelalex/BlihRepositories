/*
** EPITECH PROJECT, 2018
** find_biggest_square.c
** File description:
** find the bigger square at the given pos
*/

#include "include/my.h"

int find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int i = 0;

    for (i = col; map[row][i] != 'o' && i != nb_cols - col; i++);
    while (is_square_of_size(map, row, col, i) != 1)
        i = i - 1;
    return (i);
}
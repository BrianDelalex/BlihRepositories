/*
** EPITECH PROJECT, 2018
** is_square_of_size.c
** File description:
** return 1 if a square of the given size can be found at the right pos
*/

#include "include/my.h"

int is_square_of_size(char **map, int row, int col, int square_size)
{
    for (int i = row; i < row + square_size; i++)
        for (int j = col; j < col + square_size; j++)
            if (map[i][j] == 'o')
                return (0);
    return (1);
}
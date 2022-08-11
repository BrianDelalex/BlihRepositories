/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** uses all functions to find biggest square in map
*/

#include "struct.h"
#include "my.h"

void change_and_display(map_t map, square_t big)
{
    int i = big.line;
    int j = big.col;

    for (; i < (big.size + big.line) && i < map.lines; i++){
        for (; j < (big.size + big.col) && j < map.col; j++){
            map.map[i][j] = 'x';
        }
        j = big.col;
    }
    for (int i = 0; i <= map.lines; i++)
        my_putstr(map.map[i]);
}

int bsq(map_t map)
{
    square_t bigger = {0, 0, 0};
    int k = 0;

    if (map.lines == 1) {
        for (k = 0; map.map[0][k] != '.' && k < map.col; k++);
        bigger.line = 0;
        bigger.col = k;
        bigger.size = 1;
        change_and_display (map, bigger);
        return (0);
    }
    for (int i = 0; i <= map.lines; i++){
        for (int j = 0; j < map.col; j++)
            bigger = find_square_param(bigger, map, i, j);
    }
    change_and_display(map ,bigger);
    return (0);
}
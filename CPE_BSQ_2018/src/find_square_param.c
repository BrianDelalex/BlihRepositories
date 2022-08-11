/*
** EPITECH PROJECT, 2018
** find_square_param.c
** File description:
** finds square and return the biggest one
*/

#include "struct.h"
#include "my.h"

square_t find_square_param(square_t pv_big, map_t map, int line, int col)
{
    square_t new = {0, 0, 0};
    
    new.size = find_biggest_square(map, line, col);
    new.line = line;
    new.col = col;
    if (new.size > pv_big.size) {
        return (new);
    } else
        return (pv_big);
}
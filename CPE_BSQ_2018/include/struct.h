/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct for bsq 
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_square
{
    int line;
    int col;
    int size;
}square_t;

typedef struct s_map
{
    char **map;
    char const *filepath;
    int lines;
    int col;
}map_t;
#endif

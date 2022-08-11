/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct for my_sokoban project
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_vector
{
    int x;
    int y;
    struct s_vector *next;
}t_vector;

typedef struct s_map
{
    char **map;
    int lines;
    int cols;
    int player_x;
    int player_y;
    int box;
    int block;
    char *filepath;
    t_vector *store_list;
}t_map;

#endif

/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** creates the map
*/

#include "struct.h"
#include "my.h"

map_t create_map(char const *filepath)
{
    map_t map;

    map.filepath = filepath;
    map.lines = find_nb_of_line(filepath);
    map.col = find_nb_of_col(filepath);
    map.map = load_2d_array_from_file(filepath, map.lines, map.col);

    return (map);
}
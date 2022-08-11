/*
** EPITECH PROJECT, 2019
** free_values.c
** File description:
** frees values uses during the matchstick
*/

#include "matchstick.h"
#include <stdlib.h>

void free_values(t_map *map)
{
    for (int i = 0; map->map[i]; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}

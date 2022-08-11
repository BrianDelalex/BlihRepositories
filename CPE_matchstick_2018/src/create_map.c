/*
** EPITECH PROJECT, 2019
** create_map.c
** File description:
** return a char** containing the matches map
*/

#include "matchstick.h"
#include <stdlib.h>

t_map *put_space_or_pipe(t_map *map, int i, int j)
{
    if ((float) j - 1 >= (float) (map->lines * 2 - 1) / 2 - (i + 0.5 / 2) &&
(float) j <= (float) (map->lines * 2 - 1) / 2 +(i + 0.5 / 2))
        map->map[i][j] = '|';
    else
        map->map[i][j] = 32;
    return (map);
}

t_map *fill_with_matches(t_map *map)
{
    for (int i = 1; i < map->lines + 1; i++) {
        map->map[i][0] = '*';
        map->map[i][map->lines * 2] = '*';
        map->map[i][map->lines * 2 + 1] = 0;
        for (int j = 1; j < map->lines * 2; j++) {
            map = put_space_or_pipe(map, i, j);
        }
    }
    return (map);
}

t_map *create_map(char **av)
{
    t_map *map = malloc(sizeof(t_map));

    map->lines = my_getnbr(av[1]);
    map->max_rmv = my_getnbr(av[2]);
    map->finish = 0;
    map->map = malloc(sizeof(char *) * (map->lines + 3));
    for (int i = 0; i < map->lines + 2; i++)
        map->map[i] = malloc(sizeof(char) * (map->lines * 2 + 2));
    for (int j = 0; j < map->lines * 2 + 1; j++) {
        map->map[0][j] = '*';
        map->map[map->lines + 1][j] = '*';
    }
    map->map[0][map->lines * 2 + 1] = 0;
    map->map[map->lines + 1][map->lines * 2 + 1] = 0;
    map->map[map->lines + 2] = NULL;
    map = fill_with_matches(map);
    return (map);
}

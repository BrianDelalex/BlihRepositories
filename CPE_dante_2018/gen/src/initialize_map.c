/*
** EPITECH PROJECT, 2019
** initialise_map.c
** File description:
** initialize the char **map
*/

#include "generator.h"

char **initialize_map(int *size)
{
    char **map = malloc(sizeof(char *) * (size[1] + 1));

    srand(time(NULL));
    for (int i = 0; i < size[1]; i++) {
        map[i] = malloc(sizeof(char) * (size[0] + 2));
        for (int j = 0; j < size[0]; j++)
            map[i][j] = '*';
        map[i][size[0]] = '\n';
        map[i][size[0] + 1] = 0;
    }
    map[size[1] - 1] = remove_char_from_str(map[size[1] - 1]);
    map[size[1]] = NULL;
    return (map);
}

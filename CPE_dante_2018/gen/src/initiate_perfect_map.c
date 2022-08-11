/*
** EPITECH PROJECT, 2019
** initiate_perfect_map.c
** File description:
** initialize a perfect map
*/

#include "generator.h"

char choose_char(int i, int j, int door)
{
    if ((i % 2) != 0)
        return ('*');
    else if (j != door)
        return ('X');
    else
        return ('*');
}

char **initiate_perfect_map(int *size)
{
    char **map = malloc(sizeof(char *) * (size[1] + 1));
    int door;

    srand(time(NULL));
    for (int i = 0; i < size[1]; i++) {
        map[i] = malloc(sizeof(char) * (size[0] + 2));
        door = rand() % size[0];
        for (int j = 0; j < size[0]; j++)
            map[i][j] = choose_char(i, j, door);
        map[i][size[0]] = '\n';
        map[i][size[0] + 1] = 0;
    }
    map[size[1] - 1] = remove_char_from_str(map[size[1] - 1]);
    map[0][0] = '*';
    map[size[1] - 1][size[0] - 1] = '*';
    map[size[1]] = NULL;
    return (map);
}

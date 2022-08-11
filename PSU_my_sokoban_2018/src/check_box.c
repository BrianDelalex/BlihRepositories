/*
** EPITECH PROJECT, 2018
** check_box.c
** File description:
** checks if the boxes can move
*/

#include "struct.h"

t_map check_box(t_map map, int x, int y)
{
    if (map.map[map.player_y + 2 * y + 1][map.player_x + 2 * x] == '#' &&
        map.map[map.player_y + 2 * y][map.player_x + 2 * x + 1] == '#') {
        map.block = map.block + 1;
        return (map);
    }
    if (map.map[map.player_y + 2 * y - 1][map.player_x + 2 * x] == '#' &&
        map.map[map.player_y + 2 * y][map.player_x + 2 * x - 1] == '#') {
        map.block = map.block + 1;
        return (map);
    }
    if (map.map[map.player_y + 2 * y - 1][map.player_x + 2 * x] == '#' &&
        map.map[map.player_y + 2 * y][map.player_x + 2 * x + 1] == '#') {
        map.block = map.block + 1;
        return (map);
    }
    if (map.map[map.player_y + 2 * y + 1][map.player_x + 2 * x] == '#' &&
        map.map[map.player_y + 2 * y][map.player_x + 2 * x - 1] == '#') {
        map.block = map.block + 1;
        return (map);
    }
    return (map);
}
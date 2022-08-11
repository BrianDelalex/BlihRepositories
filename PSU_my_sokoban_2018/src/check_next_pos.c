/*
** EPITECH PROJECT, 2018
** check_next_pos.c
** File description:
** checks the next pos of the player
*/

#include "struct.h"
#include <stdlib.h>
#include "my.h"
#include <unistd.h>
#include <ncurses.h>

t_map move_box(t_map map, int x, int y)
{
    map.map[map.player_y + 2 * y][map.player_x + 2 * x] = 'X';
    map = check_box(map, x, y);
    if (map.block == map.box)
        end_lose(map);
    return (map);
}

t_map move_player(t_map map, int x, int y)
{
    map.map[map.player_y + y][map.player_x + x] = 'P';
    map.map[map.player_y][map.player_x] = 32;
    map.player_y = map.player_y + y;
    map.player_x = map.player_x + x;
    return (map);
}

int check_win(t_map map)
{
    t_vector *list = map.store_list;

    while (list != NULL) {
        if (map.map[list->y][list->x] == 'X')
            list = list->next;
        else
            return (0);
    }
    free(list);
    clear();
    for (int i = 0; i <= map.lines; i++) {
        printw(map.map[i]);
    }
    refresh();
    end_win(map);
}

t_map handle_storage(t_map map)
{
    t_vector *list = map.store_list;

    while (list != NULL) {
        if (map.map[list->y][list->x] != 'X' &&
        map.map[list->y][list->x] != 'P') {
            map.map[list->y][list->x] = 'O';
        }
        list = list->next;
    }
    free(list);
    check_win(map);
    return (map);
}

t_map check_next_pos(t_map map, int x, int y)
{
    switch(map.map[map.player_y + y][map.player_x + x]) {
        case '#':
            break;
        case 32:
            map = move_player(map, x, y);
            break;
        case 'X':
            if (map.map[map.player_y + 2 * y][map.player_x + 2 * x] != '#'
             && map.map[map.player_y + 2 * y][map.player_x + 2 * x] != 'X') {
                map = move_box(map, x, y);
                map = move_player(map, x, y);
            }
            break;
        case 'O':
            map = move_player(map, x, y);
            break;
        default:
            break;
    }
    map = handle_storage(map);
    return (map);
}

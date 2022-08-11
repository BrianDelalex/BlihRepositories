/*
** EPITECH PROJECT, 2019
** chose_turn.c
** File description:
** choses who'll play this turn
*/

#include "matchstick.h"

void draw_map(t_map *map)
{
    for (int i = 0; map->map[i]; i++) {
        my_putstr(map->map[i]);
        my_putstr("\n");
    }
}

int check_if_finish(t_map *map)
{
    int status = 0;

    for (int i = 0; map->map[i]; i++) {
        for (int j = 0; map->map[i][j]; j++) {
            status = map->map[i][j] == '|' ? 1 : status;
        }
    }
    if (status > 0)
        return (0);
    return (1);
}

int chose_turn(t_map *map)
{
    int turn = 0;
    int finish = 0;

    draw_map(map);
    my_putstr("\n");
    while (finish != 1) {
        if (turn == 0) {
            my_putstr("Your turn:\n");
            turn = 1;
            map = catch_player_action(map);
        } else if (turn == 1) {
            turn = 0;
            map = remove_match_ia(map);
        }
        if (map->finish == 84)
            return (84);
        finish = check_if_finish(map);
        draw_map(map);
        if (finish == 0)
            my_putstr("\n");
    }
    return (turn);
}

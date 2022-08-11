/*
** EPITECH PROJECT, 2019
** remove_match_ia.c
** File description:
** removes matches for the ia
*/

#include "matchstick.h"

void search_match(t_map *map, int *lines, int *matches)
{
    int match = 0;

    for (int i = 1; map->map[i]; i++) {
        for (int j = 1; map->map[i][j]; j++)
            match = map->map[i][j] == '|' ? match + 1 : match;
        if (match > *matches) {
            *matches = match;
            *lines = i;
        }
        match = 0;
    }
}

t_map *remove_match_ia(t_map *map)
{
    int lines = 0;
    int matches = 0;
    int save_matches;

    my_putstr("AI's turn...\n");
    search_match(map, &lines, &matches);
    if (matches > map->max_rmv)
        matches = map->max_rmv;
    save_matches = matches;
    for (int i = map->lines * 2; i > -1 && matches > 0; i--)
        if (map->map[lines][i] == '|') {
            map->map[lines][i] = 32;
            matches = matches - 1;
        }
    my_printf("AI removed %d match(es) from line %d\n", save_matches, lines);
    return (map);
}

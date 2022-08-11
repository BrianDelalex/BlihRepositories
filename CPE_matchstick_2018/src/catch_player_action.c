/*
** EPITECH PROJECT, 2019
** catch_player_action.c
** File description:
** catches player's action
*/

#include "matchstick.h"
#include <stdlib.h>

int get_player_line(t_map *map)
{
    char *input = NULL;
    int line = 0;
    int check;

    while (line == 0) {
        my_putstr("Line: ");
        input = use_getline();
        if (input == NULL) {
            my_putstr("Matches: ");
            return (184);
        }
        check = check_if_nb(input);
        if (check == -1)
            my_putstr("Error: invalid input (positive number expected)\n");
        else if (my_getnbr(input) <= 0 || my_getnbr(input) > map->lines)
            my_putstr("Error: this line is out of range\n");
        else
            line = my_getnbr(input);
    }
    free(input);
    return (line);
}

int get_max_matches_on_line(t_map *map, int line, char **input)
{
    int max = 0;

    if (line == 184)
        return (0);
    my_putstr("Matches: ");
    for (int i = 0; map->map[line][i]; i++)
        if (map->map[line][i] == '|')
            max = max + 1;
    *input = use_getline();
    return (max);
}

void check_nb_of_match(t_map *map, int *match, int max_on_line)
{
    if (*match > max_on_line) {
        my_putstr("Error: not enough matches on this line\n");
        *match = 0;
    } else if (*match > map->max_rmv) {
        my_printf("Error: you cannot remove more than %d matches per turn\n"
        , map->max_rmv);
        *match = 0;
    }
}

int get_player_match(t_map *map, int line)
{
    char *input = NULL;
    int match = 0;
    int max_on_line = get_max_matches_on_line(map, line, &input);

    if (input == NULL)
        return (184);
    if (check_if_nb(input) == -1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    } else if (my_getnbr(input) <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    } else
        match = my_getnbr(input);
    check_nb_of_match(map, &match, max_on_line);
    if (match == 0)
        return (0);
    free (input);
    return (match);
}

t_map *catch_player_action(t_map *map)
{
    int line = 0;
    int matches = 0;
    int save_matches;

    while ((line == 0 || matches == 0) && line != 184 && matches != 184) {
        line = get_player_line(map);
        matches = get_player_match(map, line);
    }
    if (line == 184 || matches == 184) {
        map->finish = 84;
        return (map);
    }
    save_matches = matches;
    for (int i = map->lines * 2; map->map[line][i] && matches > 0; i--) {
        if (map->map[line][i] == '|') {
            map->map[line][i] = 32;
            matches = matches - 1;
        }
    }
    my_printf("Player removed %d match(es) from line %d\n", save_matches, line);
    return (map);
}

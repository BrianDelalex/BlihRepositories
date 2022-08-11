/*
** EPITECH PROJECT, 2018
** test_map.c
** File description:
** tests create map fonction
*/

#include <criterion/criterion.h>
#include "struct.h"

t_map create_map(char const *filepath);
int check_map(char const *filepath);

Test(map, return_value_is_map)
{
    t_map test = create_map("maps/map1");

    cr_assert(test.player_x == 2);
    cr_assert(test.player_y == 11);
    free(test.map);
    free(test.store_list);
}
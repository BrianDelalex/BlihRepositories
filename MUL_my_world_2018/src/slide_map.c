/*
** EPITECH PROJECT, 2019
** slide_map.c
** File description:
** slides maps
*/

#include "my.h"

void slide_map(t_render *rd, int x, int y)
{
    sfVector2f pos;
    rd->maps->scale.x += x;
    rd->maps->scale.y += y;
    for (int i = 0; i < rd->maps->size.x; i++)
        for (int j = 0; j < rd->maps->size.y; j++) {
            rd->maps->map2d[i][j].x = rd->maps->map2d[i][j].x + x;
            rd->maps->map2d[i][j].y = rd->maps->map2d[i][j].y + y;
        }
    for (int i = 0; i < rd->nb_of_field; i++) {
        pos = sfSprite_getPosition(rd->fields[i]);
        pos.x += x;
        pos.y += y,
        sfSprite_setPosition(rd->fields[i], pos);
    }
}

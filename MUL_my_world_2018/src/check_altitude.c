/*
** EPITECH PROJECT, 2019
** check_altitude.c
** File description:
** checks if field is on a flat tile if not remove it
*/

#include "my.h"

void find_tile_index2(t_render *r, sfVector2f pos, sfVector2i *i, sfVector2i ct)
{
    if (r->maps->map2d[ct.x][ct.y].x == pos.x &&
        r->maps->map2d[ct.x][ct.y].y == pos.y) {
            i->x = ct.x;
            i->y = ct.y;
        }
}

void find_tile_index(t_render *rd, sfVector2f pos, sfVector2i *index)
{
    sfVector2i ct = {0, 0};

    for (; ct.x < rd->maps->size.x; ct.x = ct.x + 1)
        for (; ct.y < rd->maps->size.y; ct.y = ct.y + 1) {
            find_tile_index2(rd, pos, index, ct);
        }
}

void check_altitude(t_render *rd)
{
    sfVector2f pos;
    sfVector2i i;

    for (int j = 0; rd->fields != NULL && rd->fields[j]; j++) {
        pos = sfSprite_getPosition(rd->fields[j]);
        pos.x = pos.x + 64;
        find_tile_index(rd, pos, &i);
        if (rd->maps->map3d[i.x][i.y] != rd->maps->map3d[i.x + 1][i.y] ||
        rd->maps->map3d[i.x][i.y] != rd->maps->map3d[i.x][i.y + 1] ||
        rd->maps->map3d[i.x][i.y] != rd->maps->map3d[i.x + 1][i.y + 1]) {
            rd->fields = remove_sprite_from_spritetab(rd->fields, j);
            rd->nb_of_field = rd->nb_of_field - 1;
        }
    }
}

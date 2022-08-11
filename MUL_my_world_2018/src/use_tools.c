/*
** EPITECH PROJECT, 2019
** use_tools.c
** File description:
** uses tools on the map
*/

#include "my.h"

void raise_map(t_render *rd, int x, int y, int i)
{
    rd->maps->map3d[x][y] += i;
    rd->maps->map3d[x + 1][y] += i;
    rd->maps->map3d[x][y + 1] += i;
    rd->maps->map3d[x + 1][y + 1] += i;
    rd->maps->map2d = create_2d_map(rd->maps->map3d, rd->maps->size.x,
        rd->maps->size.y);
    for (int i = 0; i < rd->maps->size.x; i++)
        for (int j = 0; j < rd->maps->size.y; j++) {
            rd->maps->map2d[i][j].x = rd->maps->map2d[i][j].x +
        rd->maps->scale.x;
            rd->maps->map2d[i][j].y = rd->maps->map2d[i][j].y +
        rd->maps->scale.y;
        }
    check_altitude(rd);
}

void add_field(t_render *rd, int x, int y)
{
    int is_equal;

    sfVector2f pos = {rd->maps->map2d[x][y].x - 64, rd->maps->map2d[x][y].y};
    sfSprite *sprite = sfSprite_create();
    if (rd->money < 100)
        return;
    sprite = sfSprite_copy(rd->field_tool->sprite);
    sfSprite_setPosition(sprite, pos);
    if (rd->maps->map3d[x][y] == rd->maps->map3d[x + 1][y] &&
    rd->maps->map3d[x][y] == rd->maps->map3d[x][y + 1] &&
    rd->maps->map3d[x][y] == rd->maps->map3d[x + 1][y + 1])
        is_equal = 1;
    else
        is_equal = 0;
    if (is_equal == 1) {
        rd->fields = add_sprite_to_spritetab(rd->fields, sprite);
        rd->nb_of_field += 1;
        rd->money -= 100;
    }
}

void egalize_map(t_render *rd, int x, int y)
{
    int high = -1000;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            high = high < rd->maps->map3d[x + i][y + j] ?
            rd->maps->map3d[x + i][y + j] : high;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            rd->maps->map3d[x + i][y + j] = high;
    rd->maps->map2d = create_2d_map(rd->maps->map3d, rd->maps->size.x,
    rd->maps->size.y);
    for (int i = 0; i < rd->maps->size.x; i++)
        for (int j = 0; j < rd->maps->size.y; j++) {
            rd->maps->map2d[i][j].x = rd->maps->map2d[i][j].x +
            rd->maps->scale.x;
            rd->maps->map2d[i][j].y = rd->maps->map2d[i][j].y +
            rd->maps->scale.y;
        }
}

void choose_tool(t_render *rd, int x, int y)
{
    switch (rd->tool) {
    case 1:
        raise_map(rd, x, y, 1);
        break;
    case 2:
        add_field(rd, x, y);
        break;
    case 3:
        raise_map(rd, x, y, -1);
        break;
    case 4:
        egalize_map(rd, x, y);
    }
}

void use_tools(t_render *rd, sfMouseButtonEvent evt)
{
    int x = 0;
    int y = 0;
    float screenx = evt.x - rd->maps->map2d[0][0].x;
    float screeny = evt.y - rd->maps->map2d[0][0].y;

    x =  (int) ((screenx / 64 + screeny / 32) / 2);
    y = (int) ((screeny / 32 - (screenx / 64)) / 2);
    if (x < 0 || x >= rd->maps->size.x || y < 0 || y >= rd->maps->size.y)
        return;
    choose_tool(rd, x, y);
}

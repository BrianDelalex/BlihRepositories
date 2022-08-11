/*
** EPITECH PROJECT, 2019
** move_background.c
** File description:
** moves background
*/

#include "struct.h"

void move_background(t_render_image *bg, t_render_image *bg_bis, int move,
int init)
{
    sfVector2f pos1 = sfSprite_getPosition(bg->sprite);
    sfVector2f pos2 = sfSprite_getPosition(bg_bis->sprite);

    if (pos1.x <= -1920)
        pos1.x = init;
    if (pos2.x <= -1920)
        pos2.x = init;
    pos1.x = pos1.x - move;
    pos2.x = pos2.x - move;
    sfSprite_setPosition(bg->sprite, pos1);
    sfSprite_setPosition(bg_bis->sprite, pos2);
}

void move_obstacle(t_render_image *obstacle, int move)
{
    sfVector2f pos;

    if (obstacle->exist == 1) {
        pos = sfSprite_getPosition(obstacle->sprite);
        if (pos.x < 10) {
            sfSprite_destroy(obstacle->sprite);
            obstacle->exist = 0;
        } else {
            pos.x = pos.x - move;
            sfSprite_setPosition(obstacle->sprite, pos);
        }
    }
}

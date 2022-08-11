/*
** EPITECH PROJECT, 2019
** handle_anim_rate.c
** File description:
** handles the animation rates
*/

#include "struct.h"
#include "my.h"

void create_gravity(t_render *render)
{
    sfVector2f pos = sfSprite_getPosition(render->ply->sprite);

    if (pos.y + 250 - 35 < 738 && render->jump == 0) {
        pos.y = pos.y + 10;
        sfSprite_setPosition(render->ply->sprite, pos);
    }

}

void handle_anim_rate(t_render *render, float milliseconds, float *jump_acc)
{
    static int slower = 0;

    if (milliseconds > 20.0) {
        if (render->jump == 0)
            move_rect(&render->ply->rect, 250, 1750);
        else
            handle_sprite_jump(render, jump_acc);
        sfSprite_setTextureRect(render->ply->sprite, render->ply->rect);
        move_background(render->bg2, render->bg2_b, 1, 2000);
        move_background(render->bg3, render->bg3_b, 8, 1920);
        move_background(render->bg4, render->bg4_b, 2, 2000);
        move_obstacle(render->zombie, 5);
        if (slower % 2 == 1)
            move_rect(&render->zombie->rect, 125, 1651);
        sfClock_restart(render->clock);
        slower = slower + 1;
        create_gravity(render);
    }
}

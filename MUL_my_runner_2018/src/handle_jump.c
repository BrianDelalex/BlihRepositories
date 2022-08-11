/*
** EPITECH PROJECT, 2019
** handle_jump.c
** File description:
** handles jump anim
*/

#include "struct.h"
#include "my.h"

void handle_jump(t_render *render, int *jump_ct, float *jump_acc)
{
    if (render->jump == 1)
        *jump_ct = *jump_ct + 1;
    if (*jump_ct > 8) {
        change_anim(&render->ply->rect, 0, 0);
        *jump_ct = 0;
        render->jump = 0;
        *jump_acc = 1;
        sfClock_destroy(render->clock_jump);
    }
}

void handle_sprite_jump(t_render *render, float *jump_acc)
{
    sfVector2f pos = sfSprite_getPosition(render->ply->sprite);
    static int down = 0;

    if (*jump_acc == 1)
        down = 0;
    *jump_acc = *jump_acc + 0.1;
    if (pos.y > 350 && down == 0)
        pos.y = pos.y - (20 - *jump_acc);
    sfSprite_setPosition(render->ply->sprite, pos);
}

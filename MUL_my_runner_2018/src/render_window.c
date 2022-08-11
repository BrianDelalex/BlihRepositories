/*
** EPITECH PROJECT, 2018
** render_window.c
** File description:
** renders the window
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include "struct.h"
#include "my.h"

void render_sprite(t_render *render)
{
    sfRenderWindow_drawSprite(render->wdw, render->bg2->sprite, NULL);
    sfRenderWindow_drawSprite(render->wdw, render->bg2_b->sprite, NULL);
    sfRenderWindow_drawSprite(render->wdw, render->bg4->sprite, NULL);
    sfRenderWindow_drawSprite(render->wdw, render->bg4_b->sprite, NULL);
    sfRenderWindow_drawSprite(render->wdw, render->bg3->sprite, NULL);
    sfRenderWindow_drawSprite(render->wdw, render->bg3_b->sprite, NULL);
    sfRenderWindow_drawSprite(render->wdw, render->ply->sprite, NULL);
    if (render->zombie->exist == 1) {
        sfSprite_setTextureRect(render->zombie->sprite, render->zombie->rect);
        sfRenderWindow_drawSprite(render->wdw, render->zombie->sprite, NULL);
    }
}

void render_background(t_render *render)
{
    sfTime time = sfClock_getElapsedTime(render->clock);
    float milliseconds = time.microseconds / 1000.0;
    static int jump_ct = 0;
    static float jump_acc = 1;
    sfTime time_jump;
    float milli_jump;

    sfRenderWindow_drawSprite(render->wdw, render->bg->sprite, NULL);
    if (render->clock_jump) {
        time_jump = sfClock_getElapsedTime(render->clock_jump);
        milli_jump = time_jump.microseconds / 1000.0;
    }
    if (render->jump == 1 && milli_jump > 120.0) {
        sfClock_restart(render->clock_jump);
        move_rect(&render->ply->rect, 250, 1750);
        handle_jump(render, &jump_ct, &jump_acc);
    }
    handle_anim_rate(render, milliseconds, &jump_acc);
    render_sprite(render);
}

void call_render_function(t_render *render)
{
    analyse_events(render);
    sfRenderWindow_display(render->wdw);
    sfRenderWindow_clear(render->wdw, sfBlack);
}

void render_window(t_render *render)
{
    while (sfRenderWindow_isOpen(render->wdw)) {
        render_background(render);
        call_render_function(render);
    }
}

/*
** EPITECH PROJECT, 2019
** render_window.c
** File description:
** renders the window and all components
*/

#include "my.h"

void draw_window(t_render *render, sfVector2f **map2d)
{
    sfEvent evt;
    sfColor black = {0, 0, 0, 255};

    analyse_events(render, evt);
    sfTexture_updateFromPixels(render->tx_fb, render->fb->pixel, 800, 600, 0, 0);
    sfSprite_setTexture(render->sp_fb, render->tx_fb, sfFalse);
    sfRenderWindow_drawSprite(render->wdw, render->sp_fb, NULL);
    draw_2d_map(render->wdw, map2d);
    sfRenderWindow_display(render->wdw);
    sfRenderWindow_clear(render->wdw, black);
}

void render_window(t_render *render, sfVector2f **map2d)
{
    while (sfRenderWindow_isOpen(render->wdw)) {
        draw_window(render, map2d);
    }
}

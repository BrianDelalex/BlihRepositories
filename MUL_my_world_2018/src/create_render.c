/*
** EPITECH PROJECT, 2019
** create_render.c
** File description:
** creates render for my runner project
*/

#include "my.h"

t_render *create_render(int width, int height, int nb_bit_pixel)
{
    t_render *render = malloc(sizeof(t_render));
    sfVideoMode mode = {width, height, nb_bit_pixel};

    render->wdw = sfRenderWindow_create(mode, "my_world", sfResize | sfClose,
    NULL);
    if (!render->wdw)
        return (NULL);
    sfRenderWindow_setFramerateLimit(render->wdw, 60);
    render->fb = create_framebuffer(width, height);
    render->tx_fb = sfTexture_create(width, height);
    render->sp_fb = sfSprite_create();
    return (render);
}

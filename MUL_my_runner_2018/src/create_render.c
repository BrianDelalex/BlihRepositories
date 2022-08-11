/*
** EPITECH PROJECT, 2019
** create_render.c
** File description:
** creates render for my runner project
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <stdlib.h>
#include "struct.h"

t_render *create_render(int width, int height, int nb_bit_pixel)
{
    t_render *render = malloc(sizeof(t_render));
    sfVideoMode mode = {width, height, nb_bit_pixel};

    render->wdw = sfRenderWindow_create(mode, "my_runner", sfResize | sfClose, NULL);
    if (!render->wdw)
        return (NULL);
    sfRenderWindow_setFramerateLimit(render->wdw, 60);
    return (render);
}

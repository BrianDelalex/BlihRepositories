/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct for my runner project
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

typedef struct s_render_image
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int exist;
}t_render_image;

typedef struct s_render
{
    sfRenderWindow *wdw;
    sfEvent evt;
    sfClock *clock;
    sfClock *clock_jump;
    int jump;
    t_render_image *bg;
    t_render_image *bg2;
    t_render_image *bg2_b;
    t_render_image *bg3;
    t_render_image *bg3_b;
    t_render_image *bg4;
    t_render_image *bg4_b;
    t_render_image *ply;
    t_render_image *zombie;
}t_render;

#endif

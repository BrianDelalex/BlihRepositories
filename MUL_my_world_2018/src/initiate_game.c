/*
** EPITECH PROJECT, 2019
** initiate_game.c
** File description:
** initiates game
*/

#include "my.h"

void fill_till(t_render *rd, sfVector2f point)
{
    float screenx = point.x;
    float screeny = point.y + 1;
    int i = 0;
    float j = 0;
    float p = 0;
    sfColor c = {56, 124, 58, 255};

    for (int k = 0; k < 64; k++) {
        for (; j < 31; j += 0.5) {
            put_pixel(rd->fb, screenx + i, screeny + j, c);
            put_pixel(rd->fb, screenx + i + 1, screeny + j, c);
            i += 1;
        }
        j = 0;
        i = 0;
        screenx = point.x;
        screeny = point.y + 1;
        screenx -= k;
        screeny = screeny + p;
        p = p + 0.5;
    }
}

void initiate_game2(t_render *rd)
{
    sfVector2f point;

    for (int i = 0; i < rd->maps->size.y; i++) {
        rd->maps->map3d[i] = malloc(sizeof(int) * rd->maps->size.x);
        for (int j = 0; j < rd->maps->size.x; j++)
            rd->maps->map3d[i][j] = 00;
    }
    rd->maps->map2d = create_2d_map(rd->maps->map3d, rd->maps->size.x,
         rd->maps->size.y);
    rd->tool = 0;
    rd->maps->scale.x = 1000;
    rd->maps->scale.y = 150;
    rd->field_tool = create_render_image("ressources/field.png", 350, 63);
    rd->fields = NULL;
    rd->money = 100;
    rd->nb_of_field = 0;
    point = rd->maps->map2d[0][0];
    point.x += 1000;
    point.y += 150;
    fill_till(rd, point);
}

void initiate_game(t_render *rd)
{
    sfVideoMode mode = {1920, 1080, 32};

    sfRenderWindow_destroy(rd->wdw);
    sfTexture_destroy(rd->tx_fb);
    sfSprite_destroy(rd->sp_fb);
    rd->wdw = sfRenderWindow_create(mode, "my_world", sfResize | sfClose, NULL);
    if (!rd->wdw)
        return;
    sfRenderWindow_setFramerateLimit(rd->wdw, 60);
    rd->fb = create_framebuffer(1920, 1080);
    rd->tx_fb = sfTexture_create(1920, 1080);
    rd->sp_fb = sfSprite_create();
    initiate_game2(rd);
}

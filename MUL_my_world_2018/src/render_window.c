/*
** EPITECH PROJECT, 2019
** render_window.c
** File description:
** renders the window and all components
*/

#include "my.h"

void draw_box(t_render *rd, sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *rcx = sfRectangleShape_create();
    sfColor c =  {140, 140, 140, 255};

    sfRectangleShape_setPosition(rcx, pos);
    sfRectangleShape_setSize(rcx, size);
    sfRectangleShape_setFillColor(rcx, c);
    sfRenderWindow_drawShape(rd->wdw, (sfShape *)rcx, NULL);
}

void draw_toolbar(t_render *rd)
{
    sfVector2f size = {75, 75};
    sfVector2f pos1 = {50, 50};
    sfVector2f pos2 = {150, 50};
    sfVector2f pos3 = {250, 50};
    sfVector2f post1 = {50, 120};
    sfVector2f post2 = {150, 120};
    sfVector2f post3 = {250, 120};
    sfVector2f posfieldtxt = {375, 120};

    draw_box(rd, pos1, size);
    draw_box(rd, pos2, size);
    draw_box(rd, pos3, size);
    draw_text(rd, "Raise", post1, 35);
    draw_text(rd, "Lower", post2, 35);
    draw_text(rd, "Egalize",post3, 35);
    draw_text(rd, "Field", posfieldtxt, 35);
    sfRenderWindow_drawSprite(rd->wdw, rd->field_tool->sprite, NULL);
}

void display_fields(t_render *rd)
{
    if (rd->fields != NULL)
        for (int i = 0; rd->fields[i] != NULL; i++)
            sfRenderWindow_drawSprite(rd->wdw, rd->fields[i], NULL);
}

void draw_window(t_render *rd, render_image_t *background)
{
    sfEvent evt;
    sfColor bg = {76, 93, 255, 255};
    sfVector2f money_pos = {1800, 20};

    sfRenderWindow_drawSprite(rd->wdw, background->sprite, NULL);
    analyse_events(rd, evt);
    draw_2d_map(rd);
    display_fields(rd);
    draw_toolbar(rd);
    draw_text(rd, strconcat(long_to_char(rd->money), " $"), money_pos, 35);
    sfTexture_updateFromPixels(rd->tx_fb, rd->fb->pixel, 1920, 1080, 0, 0);
    sfSprite_setTexture(rd->sp_fb, rd->tx_fb, sfFalse);
    sfRenderWindow_drawSprite(rd->wdw, rd->sp_fb, NULL);
    sfRenderWindow_display(rd->wdw);
    sfRenderWindow_clear(rd->wdw, bg);
}

void render_window(t_render *render)
{
    sfClock *clock = sfClock_create();
    render_image_t *background = create_render_image("ressources/sky", 0, 0);

    while (sfRenderWindow_isOpen(render->wdw)) {
        draw_window(render, background);
        manage_time(render, clock);
    }
}

/*
** EPITECH PROJECT, 2019
** chose_map_size.c
** File description:
** users can chose the size of the map
*/

#include "my.h"

void display_input_rectangle(t_render *rd)
{
    sfVector2f posrcx = {320, 250};
    sfVector2f posrcy = {320, 320};
    sfVector2f posbutton = {490, 250};
    sfVector2f sizebutton = {70, 100};
    sfVector2f size = {80, 30};
    sfRectangleShape *rcx = sfRectangleShape_create();

    sfRectangleShape_setPosition(rcx, posrcx);
    sfRectangleShape_setSize(rcx, size);
    sfRectangleShape_setFillColor(rcx, sfWhite);
    sfRectangleShape_setOutlineThickness(rcx, 4.);
    sfRectangleShape_setOutlineColor(rcx, sfBlack);
    sfRenderWindow_drawShape(rd->wdw, (sfShape *)rcx, NULL);
    sfRectangleShape_setPosition(rcx, posrcy);
    sfRenderWindow_drawShape(rd->wdw, (sfShape *)rcx, NULL);
    sfRectangleShape_setSize(rcx, sizebutton);
    sfRectangleShape_setPosition(rcx, posbutton);
    sfRenderWindow_drawShape(rd->wdw, (sfShape *)rcx, NULL);
}

void display_choice_box(t_render *rd)
{
    sfVector2f posrect = {200, 200};
    sfVector2f postxt = {200, 150};
    sfVector2f s = {400, 200};
    sfVector2f postxtwidth = {205, 250};
    sfVector2f postxtheitgh = {205, 320};
    sfVector2f postile1 = {410, 250};
    sfVector2f postile2 = {410, 320};
    sfColor c = {255, 255, 255, 255};

    draw_rectangle(rd->fb, posrect, s, c);
    sfTexture_updateFromPixels(rd->tx_fb, rd->fb->pixel, 800, 600, 0, 0);
    sfSprite_setTexture(rd->sp_fb, rd->tx_fb, sfFalse);
    sfRenderWindow_drawSprite(rd->wdw, rd->sp_fb, NULL);
    draw_text(rd, "Chose your map's size :", postxt, 40);
    display_input_rectangle(rd);
    draw_text(rd, "WIDTH :", postxtwidth, 30);
    draw_text(rd, "HEITGH :", postxtheitgh, 30);
    draw_text(rd, "Tiles", postile1, 30);
    draw_text(rd, "Tiles", postile2, 30);
}

void display_choice_window(t_render *rd)
{
    sfEvent evt;
    sfColor grey = {38, 58, 82, 255};
    sfVector2f poswidth = {345 - (my_strlen(int_to_char(rd->maps->size.x))
        / 2 * 5), 250};
    sfVector2f posheitgh = {345 - (my_strlen(int_to_char(rd->maps->size.y))
        / 2 * 5), 320};
    sfVector2f posplay = {500, 285};

    analyse_events_choice(rd, evt);
    display_choice_box(rd);
    draw_text(rd, int_to_char(rd->maps->size.x), poswidth, 25);
    draw_text(rd, int_to_char(rd->maps->size.y), posheitgh, 25);
    draw_text(rd, "PLAY", posplay, 25);
    sfRenderWindow_display(rd->wdw);
    sfRenderWindow_clear(rd->wdw, grey);
}

void chose_map_size(t_render *rd)
{
    while (sfRenderWindow_isOpen(rd->wdw) && rd->maps->map3d == NULL) {
        display_choice_window(rd);
    }
}

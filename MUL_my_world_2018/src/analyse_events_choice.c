/*
** EPITECH PROJECT, 2019
** analyse_event_choice.c
** File description:
** analyses event for the choice window
*/

#include "my.h"

void manage_mouse_click(sfMouseButtonEvent evt, t_render *rd)
{
    if (evt.x >= 320 && evt.x <= 400 && evt.y >= 250 && evt.y <= 280) {
        rd->maps->x_select = 1;
        rd->maps->y_select = 0;
    } else if (evt.x >= 320 && evt.x <= 400 && evt.y >= 320 && evt.y <= 350) {
        rd->maps->y_select = 1;
        rd->maps->x_select = 0;
    } else {
        rd->maps->y_select = 0;
        rd->maps->x_select = 0;
    }
    if (evt.x >= 490 && evt.x <= 560 && evt.y >= 250 && evt.y <= 350)
        if (rd->maps->size.x > 0 && rd->maps->size.y > 0) {
            rd->maps->map3d = malloc(sizeof(int *) * rd->maps->size.y);
        }
}

void add_number_to_selected(int nb, t_render *rd)
{
    if (rd->maps->x_select == 1 && ((rd->maps->size.x / 10) < 10)) {
        rd->maps->size.x = rd->maps->size.x * 10;
        rd->maps->size.x = rd->maps->size.x + nb;
    }
    if (rd->maps->y_select == 1 && ((rd->maps->size.y / 10) < 10)) {
        rd->maps->size.y = rd->maps->size.y * 10;
        rd->maps->size.y = rd->maps->size.y + nb;
    }
}

void manage_key_press(sfKeyEvent key, t_render *rd)
{
    if (key.code == sfKeyNum0)
        add_number_to_selected(0, rd);
    if (key.code == sfKeyNum1)
        add_number_to_selected(1, rd);
    if (key.code == sfKeyNum2)
        add_number_to_selected(2, rd);
    if (key.code == sfKeyNum3)
        add_number_to_selected(3, rd);
    if (key.code == 51 || key.code == sfKeyNum4)
        add_number_to_selected(4, rd);
    if (key.code == sfKeyNum5)
        add_number_to_selected(5, rd);
    if (key.code == 56 || key.code == sfKeyNum6)
        add_number_to_selected(6, rd);
    if (key.code == sfKeyNum7)
        add_number_to_selected(7, rd);
    if (key.code == sfKeyNum8)
        add_number_to_selected(8, rd);
    if (key.code == sfKeyNum9)
        add_number_to_selected(9, rd);
}

void close_window_choice(sfRenderWindow *wdw, sfEvent event, t_render *rd)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(wdw);
    if (event.type == sfEvtKeyPressed && event.key.code == 59) {
        if (rd->maps->x_select == 1)
            rd->maps->size.x = (int) rd->maps->size.x / 10;
        if (rd->maps->y_select == 1)
            rd->maps->size.y = (int) rd->maps->size.y / 10;
    }
}

void analyse_events_choice(t_render *rd, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(rd->wdw, &evt)) {
        close_window_choice(rd->wdw, evt, rd);
        if (evt.type == sfEvtMouseButtonPressed) {
            manage_mouse_click(evt.mouseButton, rd);
        }
        if (evt.type == sfEvtKeyPressed && (rd->maps->x_select == 1 ||
            rd->maps->y_select == 1))
            manage_key_press(evt.key, rd);
    }
}

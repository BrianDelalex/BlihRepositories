/*
** EPITECH PROJECT, 2018
** analyse_event.c
** File description:
** analyses events
*/

#include "my.h"

void manage_map_movement(sfKeyEvent key, t_render *rd)
{
    if (key.code == sfKeyLeft)
        slide_map(rd, 20, 0);
    if (key.code == sfKeyRight)
        slide_map(rd, -20, 0);
    if (key.code == sfKeyUp)
        slide_map(rd, 0, 10);
    if (key.code == sfKeyDown)
        slide_map(rd, 0, -10);
    if (key.code == sfKeyEscape)
        sfRenderWindow_close(rd->wdw);
}

void close_window(sfRenderWindow *wdw, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
}

void analyse_events(t_render *rd, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(rd->wdw, &evt)) {
        close_window(rd->wdw, evt);
        if (evt.type == sfEvtMouseButtonPressed) {
            manage_game_click(rd, evt.mouseButton);
        }
        if (evt.type == sfEvtKeyPressed)
            manage_map_movement(evt.key, rd);
    }
}

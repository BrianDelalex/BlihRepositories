/*
** EPITECH PROJECT, 2018
** analyse_event.c
** File description:
** analyses events
*/

#include "my.h"

void close_window(sfRenderWindow *wdw, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
}

void analyse_events(t_render *render, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(render->wdw, &evt)) {
        close_window(render->wdw, evt);
    }
}

/*
** EPITECH PROJECT, 2018
** analyse_event.c
** File description:
** analyses events
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void manage_mouse_click(sfMouseButtonEvent event, sfSprite *duck, int *living)
{
    if (event.x >= sfSprite_getPosition(duck).x &&
    event.x <= sfSprite_getPosition(duck).x + 110) {
        if (event.y >= sfSprite_getPosition(duck).y &&
        event.y <= sfSprite_getPosition(duck).y + 110)
            *living = 0;
    }
}

void close_window(sfRenderWindow *wdw, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
}

void analyse_events(sfRenderWindow *wdw, sfEvent event,
sfSprite *duck, int *living)
{
    sfVector2i pos = {0,0};
    sfMouseButtonEvent ms_event;
    sfWindow *wdw2 = malloc(sizeof(sfWindow *));

    wdw2 = (sfWindow *) wdw;
    while (sfRenderWindow_pollEvent(wdw, &event)) {
        close_window(wdw, event);
        if (event.type == sfEvtMouseButtonPressed) {
            ms_event.type = sfEvtMouseButtonPressed;
            ms_event.button = 1;
            ms_event.x = sfMouse_getPosition(wdw2).x;
            ms_event.y = sfMouse_getPosition(wdw2).y;
            manage_mouse_click(ms_event, duck, living);
        }
    }
}

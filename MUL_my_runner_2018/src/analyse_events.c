/*
** EPITECH PROJECT, 2018
** analyse_event.c
** File description:
** analyses events
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>

void handle_input(t_render *render)
{
    sfVector2f pos = sfSprite_getPosition(render->ply->sprite);

    if (render->evt.type == sfEvtKeyPressed)
        if (sfKeyboard_isKeyPressed(sfKeySpace) && pos.y + 250 - 35 >= 738) {
            change_anim(&render->ply->rect, 0, 230);
            render->jump = 1;
            render->clock_jump = sfClock_create();
        }
}

void close_window(sfRenderWindow *wdw, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wdw);
}

void analyse_events(t_render *render)
{
    while (sfRenderWindow_pollEvent(render->wdw, &render->evt)) {
        handle_input(render);
        close_window(render->wdw, render->evt);
    }
}

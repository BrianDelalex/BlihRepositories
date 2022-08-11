/*
** EPITECH PROJECT, 2019
** manage_game_click.c
** File description:
** manages click in the game
*/

#include "my.h"

void manage_game_click2(t_render *rd, sfMouseButtonEvent evt)
{
    if (evt.x > 150 && evt.x < 225 && evt.y > 50 && evt.y < 125)
        rd->tool = 3;
    else if (evt.x > 250 && evt.x < 325 && evt.y > 50 && evt.y < 125)
        rd->tool = 4;
    else
        use_tools(rd, evt);
}

void manage_game_click(t_render *rd, sfMouseButtonEvent evt)
{
    if (evt.x > 50 && evt.x < 125 && evt.y > 50 && evt.y < 125)
        rd->tool = 1;
    else if (evt.x > 350 && evt.x < 478 && evt.y > 65 && evt.y < 129)
        rd->tool = 2;
    else
        manage_game_click2(rd, evt);
}

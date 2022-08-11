/*
** EPITECH PROJECT, 2019
** draw_text.c
** File description:
** draws text
*/

#include "my.h"

void draw_text(t_render *rd, char *str, sfVector2f pos, int size)
{
    sfFont *f = sfFont_createFromFile("ressources/font.ttf");
    sfText *txt = sfText_create();

    sfText_setPosition(txt, pos);
    sfText_setFont(txt, f);
    sfText_setString(txt, str);
    sfText_setColor(txt, sfBlack);
    sfText_setCharacterSize(txt, size);
    sfRenderWindow_drawText(rd->wdw, txt, NULL);
}

/*
** EPITECH PROJECT, 2018
** create_scoreboard.c
** File description:
** creates a Text uses as score
*/

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

sfText *create_scoreboard(char *str)
{
    sfText *scoreboard = sfText_create();
    sfVector2f position = {640, 20};
    sfFont *font = sfFont_createFromFile("ressources/BEBAS___.ttf");

    sfText_setString(scoreboard, str);
    sfText_setFont(scoreboard, font);
    sfText_setPosition(scoreboard, position);
    sfText_setColor(scoreboard, sfRed);
    sfText_setCharacterSize(scoreboard, 30);
    return (scoreboard);
}
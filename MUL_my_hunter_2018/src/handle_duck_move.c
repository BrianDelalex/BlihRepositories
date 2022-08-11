/*
** EPITECH PROJECT, 2018
** handle_duck_move.c
** File description:
** handle and time the duck's movement
*/

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

void handle_duck_move(sfClock *clock, sfSprite *duck, int *random_y)
{
    sfVector2f move = {4, *random_y * 0.1};
    sfTime time_ = sfClock_getElapsedTime(clock);
    float milliseconds = time_.microseconds / 1000.0;
    sfVector2f reset_pos = {0, sfSprite_getPosition(duck).y};

    if (milliseconds > 10.0) {
        sfSprite_move(duck, move);
        sfClock_restart(clock);
    }
    if (sfSprite_getPosition(duck).x == 1200) {
        sfSprite_setPosition(duck, reset_pos); 
    }
    if (sfSprite_getPosition(duck).y > 526 || sfSprite_getPosition(duck).y < 0)
        *random_y = - (*random_y);
}

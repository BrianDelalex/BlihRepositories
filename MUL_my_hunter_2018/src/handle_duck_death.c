/*
** EPITECH PROJECT, 2018
** handle_duck_death.c
** File description:
** destroy the death duck and create a new one
*/

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void handle_duck_death(sfClock *clock, sfSprite *duck,
 int *living, sfText *score)
{
    sfTime time;
    float seconds;
    sfVector2f fall = {0, 8};
    sfVector2f restart = {0, create_random_value(0, 524)};
    char *score_str = "\0";

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds < 1.5) {
        sfSprite_setRotation(duck, 180.0);
        if (sfSprite_getPosition(duck).y < 634)
            sfSprite_move(duck, fall);
    } else {
        sfClock_restart(clock);
        *living = 1;
        score_str = my_strcpy(score_str, 
         my_int_to_str(my_getnbr(sfText_getString(score)) + 100));
        sfText_setString(score, score_str);
        sfSprite_setRotation(duck, 0.0);
        sfSprite_setPosition(duck, restart);
    }
}

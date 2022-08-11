/*
** EPITECH PROJECT, 2018
** time.c
** File description:
** time functions
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

void move_rect(sfIntRect *rect, int offset, int max_value);

void time_anim(sfClock *clock, sfIntRect *rect)
{
    sfTime time;
    float milliseconds;

    time = sfClock_getElapsedTime(clock);
    milliseconds = time.microseconds / 1000.0;
    if (milliseconds > 66.66) {
        move_rect(rect, 110, 220);
        sfClock_restart(clock);
    }
}
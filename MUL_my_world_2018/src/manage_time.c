/*
** EPITECH PROJECT, 2019
** manage_time.c
** File description:
** manages the time
*/

#include "my.h"

void manage_time(t_render *rd, sfClock *cl)
{
    sfTime time = sfClock_getElapsedTime(cl);
    int secondes = time.microseconds / 1000000;

    if (secondes > 2) {
        rd->money += 50 * rd->nb_of_field;
        sfClock_restart(cl);
    }
}

/*
** EPITECH PROJECT, 2019
** project_iso_point.c
** File description:
** project a 3D pos in a 2D one
*/

#include "my.h"

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point;
    float angle_x = (float) ((45 * M_PI) / 180);
    float angle_y = (float) ((35 * M_PI) / 180);

    point.x = (float)((cos(angle_x) * x) - (cos(angle_x) * y));
    point.y =  (float)((sin(angle_y) * y) + (sin(angle_y) * x) - z);
    return (point);
}

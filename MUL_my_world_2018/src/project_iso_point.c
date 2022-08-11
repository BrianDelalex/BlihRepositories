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

    point.x = (x - y) * 64;
    point.y = (x + y) * 32 - z;
    return (point);
}

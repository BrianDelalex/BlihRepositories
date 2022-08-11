/*
** EPITECH PROJECT, 2019
** create_2d_map.c
** File description:
** create a 2D  map from a 3D one
*/

#include "my.h"

sfVector2f **create_2d_map(int **map3d, int x, int y)
{
    sfVector2f **map2d;
    int heigth = y;
    int width = x;

    map2d = malloc(sizeof(sfVector2f *) * heigth);
    for (int i = 0; i < heigth; i++)
        map2d[i] = malloc(sizeof(sfVector2f) * width);
    for (int i = 0; i < heigth; i++)
        for (int j = 0; j < width; j++)
            map2d[i][j] = project_iso_point(i, j, map3d[i][j] * 10);
    return (map2d);
}

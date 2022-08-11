/*
** EPITECH PROJECT, 2019
** create_2d_map.c
** File description:
** create a 2D  map from a 3D one
*/

#include "my.h"

sfVector2f **create_2d_map(int **map3D)
{
    sfVector2f **map2D;
    int heigth = 6;
    int width = 6;

    //for (; map3D[width][0]; width++);
    //for (; map3D[0][heigth]; heigth++);
    map2D = malloc(sizeof(sfVector2f *) * heigth);
    for (int i = 0; i < heigth; i++)
        map2D[i] = malloc(sizeof(sfVector2f) * width);
    for (int i = 0; i < heigth; i++)
        for (int j = 0; j < width; j++) {
            printf("i: %d j: %d\n", i, j);
            map2D[i][j] = project_iso_point(i * 64, j * 64, map3D[i][j] * 25);
        }
    return (map2D);
}

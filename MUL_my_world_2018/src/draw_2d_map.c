/*
** EPITECH PROJECT, 2019
** draw_2d_map.c
** File description:
** draws a 2dmap
*/

#include "my.h"

void draw_vertex(t_render *rd, int i, int j)
{
    if (i == rd->maps->size.x - 1 && j == rd->maps->size.y - 1)
        return;
    if (i == rd->maps->size.x - 1 && j != rd->maps->size.y - 1)
        sfRenderWindow_drawVertexArray(rd->wdw, create_line(
    rd->maps->map2d[j][i], rd->maps->map2d[j + 1][i]), NULL);
    else if (j == rd->maps->size.y - 1 && i != rd->maps->size.x - 1)
        sfRenderWindow_drawVertexArray(rd->wdw, create_line(
            rd->maps->map2d[j][i], rd->maps->map2d[j][i + 1]), NULL);
    else {
        sfRenderWindow_drawVertexArray(rd->wdw, create_line(
            rd->maps->map2d[j][i], rd->maps->map2d[j][i + 1]), NULL);
        sfRenderWindow_drawVertexArray(rd->wdw, create_line(
            rd->maps->map2d[j][i], rd->maps->map2d[j + 1][i]), NULL);
    }
}

void draw_2d_map(t_render *rd)
{
    int width = rd->maps->size.x;
    int heigth = rd->maps->size.y;

    for (int j = 0; j < width ; j++) {
        for (int i = 0; i < heigth; i++) {
            draw_vertex(rd, i, j);
         }
    }
}

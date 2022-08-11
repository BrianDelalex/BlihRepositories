/*
** EPITECH PROJECT, 2019
** draw_2d_map.c
** File description:
** draws a 2dmap
*/

#include "my.h"

void draw_vertex(sfRenderWindow *wdw, sfVector2f **map2d, int i, int j)
{
    if (i == 5 && j == 5)
        return;
    if (i == 5 && j != 5)
        sfRenderWindow_drawVertexArray(wdw, create_line(map2d[j][i],
            map2d[j + 1][i]), NULL);
    else if (j == 5 && i != 5)
        sfRenderWindow_drawVertexArray(wdw, create_line(map2d[j][i],
            map2d[j][i + 1]), NULL);
    else {
        sfRenderWindow_drawVertexArray(wdw, create_line(map2d[j][i],
            map2d[j][i + 1]), NULL);
        sfRenderWindow_drawVertexArray(wdw, create_line(map2d[j][i],
            map2d[j + 1][i]), NULL);
    }
}

int draw_2d_map(sfRenderWindow *wdw, sfVector2f **map2d)
{
    int width = 0;
    int heigth = 0;

    for (int j = 0; map2d[j]; j++) {
        for (int i = 0; i < 6; i++) {
            draw_vertex(wdw, map2d, i, j);
         }
    }

}

/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for my_world project
*/

#include "my.h"

int main(void)
{
    t_render *render = create_render(800, 600, 32);
    int map[6][6] = {
        {00,00,00,00,00,00},
        {00,00,00,00,00,00},
        {00,00,00,05,03,00},
        {00,00,00,00,00,00},
        {00,00,00,00,00,00},
        {00,00,00,00,00,00}
    };
    int **mapb = malloc(sizeof(int *) * 6);
    for (int i = 0; i < 6; i++) {
        mapb[i] = malloc(sizeof(int) * 6);
        for (int j = 0; j < 6; j++)
            mapb[i][j] = 00;
    }
    mapb[3][2] = 05;
    mapb[4][2] = 03;
    sfVector2f **map2D = create_2d_map(mapb);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            map2D[i][j].x = map2D[i][j].x + 300;
            map2D[i][j].y = map2D[i][j].y + 150;
        }
    render_window(render, map2D);
}

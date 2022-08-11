/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for my_world project
*/

#include "my.h"

int main(void)
{
    t_render *rd = create_render(800, 600, 32);

    rd->maps = malloc(sizeof(t_maps));
    rd->maps->map3d = NULL;
    rd->maps->size.x = 64;
    rd->maps->size.y = 64;
    rd->fb = create_framebuffer(800, 600);
    chose_map_size(rd);
    if (rd->maps->map3d == NULL)
        return (84);
    initiate_game(rd);
    for (int i = 0; i < rd->maps->size.x; i++)
        for (int j = 0; j < rd->maps->size.y; j++) {
            rd->maps->map2d[i][j].x = rd->maps->map2d[i][j].x + 1000;
            rd->maps->map2d[i][j].y = rd->maps->map2d[i][j].y + 150;
        }
    render_window(rd);
}

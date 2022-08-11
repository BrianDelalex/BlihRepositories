/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main fucntion of my_runner project
*/

#include "struct.h"
#include "my.h"

int main(int ac, char **av)
{
    t_render *render = create_render(1920, 1080, 32);

    render->clock = sfClock_create();
    create_background(render);
    render_window(render);
}

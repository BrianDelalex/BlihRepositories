/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for solver
*/

#include "solver.h"


int main(int ac, char **av)
{
    FILE *fd;
    char *gl;
    char **map = NULL;

    if (ac != 2)
        return (84);
    fd = fopen(av[1], "r");
    if (fd == NULL)
        return (84);
    while (1) {
        gl = use_getline(fd);
        if (gl == NULL)
            break;
        map = add_char_to_tab(gl, map);
    }
    search_exit(map);
}

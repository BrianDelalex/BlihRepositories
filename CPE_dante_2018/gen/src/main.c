/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function of generator
*/

#include "generator.h"
#include "../../include/my.h"

void handle_errors(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        exit(84);
    for (int i = 0; av[1][i]; i++)
        if (!(IS_DIGIT(av[1][i])))
            exit(84);
    for (int i = 0; av[2][i]; i++)
        if (!(IS_DIGIT(av[2][i])))
            exit(84);
}

int main(int ac, char **av)
{
    int size[2];
    char **map;

    handle_errors(ac, av);
    if (av[3] && my_strcmp(av[3], "[perfect]")) {
        size[0] = my_getnbr(av[1]);
        size[1] = my_getnbr(av[2]);
        map = initiate_perfect_map(size);
        for (int i = 0; map[i]; i++)
            my_printf("%s", map[i]);
    } else {
        size[0] = my_getnbr(av[1]);
        size[1] = my_getnbr(av[2]);
        map = initialize_map(size);
        for (int i = 0; map[i]; i++)
            my_printf("%s", map[i]);
    }
    return (0);
}

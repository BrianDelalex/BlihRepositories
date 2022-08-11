/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for FASTAtools
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    int flags = handle_error(ac, av);
    int k = 0;
    char **file;

    if (flags == 84)
        return (84);
    if (flags == 4 && av[2] && is_a_number(av[2]))
        k = my_getnbr(av[2]);
    else if (flags == 4)
        return (84);
    file = get_file();
    if (file == NULL)
        return (84);
    choose_display(flags, k, file);
}

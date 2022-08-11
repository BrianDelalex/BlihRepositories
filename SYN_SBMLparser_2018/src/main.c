/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for SBMLparser
*/

#include "../include/my.h"

int handle_error(int ac)
{
    if (ac < 2)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int he = handle_error(ac);
    FILE *file;
    list_t *list = NULL;
    parse_t *parse = create_parse(ac, av);

    if (parse == NULL)
        return (84);
    if (he == 84)
        return (84);
    file = fopen(av[1], "r");
    if (file == NULL)
        return (84);
    if (parse->i == 1)
        read_with_i_flag(file, parse);
    else
        read_sbml_file(list, file);
}

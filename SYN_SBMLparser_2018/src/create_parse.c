/*
** EPITECH PROJECT, 2019
** create_parse.c
** File description:
** parse program input into the parse struct
*/

#include "../include/my.h"

parse_t *create_parse(int ac, char **av)
{
    parse_t *parse = malloc(sizeof(parse_t));

    if (ac >= 3 && my_strcmp(av[2], "-i"))
        parse->i = 1;
    else if (ac >= 3)
        return (NULL);
    else
        parse->i = 0;
    if (ac >= 4)
        parse->i_name = av[3];
    else
        parse->i_name = NULL;
    if (ac >= 5 && my_strcmp(av[4], "-e"))
        parse->e = 1;
    else if (ac >= 5 && my_strcmp(av[4], "-json"))
        parse->json = 1;
    else {
        parse->e = 0;
        parse->json = 0;
    }
    return (parse);
}

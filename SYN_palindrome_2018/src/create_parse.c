/*
** EPITECH PROJECT, 2019
** create_parse.c
** File description:
** parse program input into the parse struct
*/

#include "../include/my.h"

parse_t *create_parse2(char **av, parse_t *parse)
{
    parse->i_max = 100;
    parse->i_min = 0;
    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], "-imin"))
            parse->i_min = my_getnbr(av[i + 1]);
        if (my_strcmp(av[i], "-imax"))
            parse->i_max = my_getnbr(av[i + 1]);
    }
    if (parse->base <= 1 || parse->base > 10)
        return (NULL);
    if (parse->i_min > parse->i_max)
        return (NULL);
    if (!(is_a_palindrome(parse->pal, parse->base)))
        return (NULL);
    return (parse);
}

parse_t *create_parse(int ac, char **av)
{
    parse_t *parse = malloc(sizeof(parse_t));

    if (ac < 3)
        return (NULL);
    if (my_strcmp(av[1], "-n"))
        parse->nb = my_getnbr(av[2]);
    else
        parse->nb = -1;
    if (my_strcmp(av[1], "-p"))
        parse->pal = my_getnbr(av[2]);
    else
        parse->pal = -1;
    if (av[3] && my_strcmp(av[3], "-b"))
        parse->base = my_getnbr(av[4]);
    else
        parse->base = 10;
    if (parse->nb < 0 && parse->pal < 0)
        return (NULL);
    return (create_parse2(av, parse));
}

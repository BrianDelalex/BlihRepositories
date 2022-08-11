/*
** EPITECH PROJECT, 2019
** handle_error.c
** File description:
** handle errors
*/

#include "../include/my.h"

int is_a_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!(IS_DIGIT(str[i])))
            return (0);
    return (1);
}

int handle_error(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (my_strcmp(av[1], "-h"))
        return (0);
    else if (is_a_number(av[1]))
        if (my_getnbr(av[1]) > 0 && my_getnbr(av[1]) <= 7)
            return (my_getnbr(av[1]));
        else
            return (84);
    else
        return (84);

}

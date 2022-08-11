/*
** EPITECH PROJECT, 2019
** handle_error.c
** File description:
** handle errors
*/

#include "../include/my.h"

int is_in_tab(char **tab, char *str)
{
    int check = 0;

    for (int i = 0; tab[i]; i++)
        if (my_strcmp(tab[i], str))
            check = 1;
    return (check);
}

int is_a_number(char *str)
{
    int check = 1;

    for (int i = 0; str[i]; i++)
        if (!(IS_DIGIT(str[i])))
            check = 0;
    return (check);
}

int handle_error(char **av)
{
    char *flags[6] = {"-n", "-p", "-b", "-imin", "-imax", NULL};
    int n = 0;
    int p = 0;

    for (int i = 1; av[i]; i++) {
        if (!(is_in_tab(flags, av[i])) && !(is_a_number(av[i]))) {
            printf("invalid argument\n");
            return (84);
        }
        if (my_strcmp(av[i], "-n"))
            n = 1;
        if (my_strcmp(av[i], "-p"))
            p = 1;
    }
    if (p == 1 && n == 1)
        return (84);
    return (0);
}

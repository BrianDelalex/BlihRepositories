/*
** EPITECH PROJECT, 2018
** handle_errors.c
** File description:
** handles errors
*/

#include "my.h"
#include <stdlib.h>

int check_flag(char **av)
{
    if (av[3][0] != '0' && av[3][0] != '1') {
        my_puterror("Unknown flag");
        exit(84);
    } else
        return (0);
}

int handle_errors(int ac, char **av)
{
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("USAGE\n   ./103cipher message key flag\n\nDESCRIPTION");
            my_putstr("\n   message    a message, made of ASCII characters");
            my_putstr("\n   key        the encyption key, made of ASCII \
characters");
            my_putstr("\n   flag       0 for message to be encrypted, 1 to be \
decrypted\n");
            exit(84);
        }
    if (ac < 4) {
        my_puterror("Not enougth arguments");
        exit(84);
    } else if (ac > 4) {
        my_puterror("Too much arguments");
        exit(84);
    }
    check_flag(av);
}

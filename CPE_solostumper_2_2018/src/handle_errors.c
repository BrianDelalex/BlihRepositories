/*
** EPITECH PROJECT, 2019
** handle_errors.c
** File description:
** handles errors of program input
*/

#include "my.h"

int handle_errors(int ac)
{
    if (ac > 3) {
        my_puterror("Error: too much arguments.\n");
        return (84);
    } else if (ac < 3) {
        my_puterror("Error: not enought arguments.\n");
        return (84);
    } else
        return (0);
}

/*
** EPITECH PROJECT, 2018
** convert_to_octal.c
** File description:
** convert the given in to an octal value which is return in a char *
*/

#include <stdlib.h>

char *convert_to_octal(int nb)
{
    char *oct = malloc(sizeof(char) * 5);

    oct[4] = 0;
    oct[0] = '\\';
    for (int i = 3; i > 0; i--) {
        oct[i] = nb % 8 + 48;
        nb = nb / 8;
    }
    return (oct);
}

/*
** EPITECH PROJECT, 2019
** echo_function.c
** File description:
** echo function
*/

#include "../include/my.h"

int echo_function(char *input)
{
    char *str = cut_command(input);

    if (strncp(str, "-n ", 3) == 1) {
        my_putstr(str + 3);
    } else {
        my_putstr(str);
        my_putchar('\n');
    }
    free(str);
    return (1);
}

/*
** EPITECH PROJECT, 2019
** check_redirect_char.c
** File description:
** check which redirect char is it
*/

#include "my.h"

int check_redirect_char(char *str)
{
    if (my_strcmp(str, ">") == 1)
        return (1);
    if (my_strcmp(str, ">>") == 1)
        return (2);
    if (my_strcmp(str, "<") == 1)
        return (3);
    if (my_strcmp(str, "<<") == 1)
        return (4);
    if (my_strcmp(str, "|") == 1)
        return (5);
    if (my_strcmp(str, "||") == 1)
        return (6);
    if (my_strcmp(str, "&&") == 1)
        return (7);
    return (0);
}

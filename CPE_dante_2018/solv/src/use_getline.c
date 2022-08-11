/*
** EPITECH PROJECT, 2019
** use_nextline.c
** File description:
** uses the nextline and return a char *
*/

#include <stdio.h>
#include "solver.h"

char *use_getline(FILE *fd)
{
    char *input = NULL;
    size_t len = 0;
    int ret = 0;

    ret = getline(&input, &len, fd);
    if (ret == -1 || ret == 0)
        return (NULL);
    return (input);
}

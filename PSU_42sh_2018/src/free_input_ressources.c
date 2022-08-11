/*
** EPITECH PROJECT, 2019
** free_input_ressources.c
** File description:
** frees the input's ressources
*/

#include "../include/my.h"

void free_input_ressources(char *input, char **com)
{
    free(input);
    for (int i = 0; com[i]; i++)
        free(com[i]);
    free(com);
}

/*
** EPITECH PROJECT, 2019
** find_reaction_name.c
** File description:
** find and return the reaction name
*/

#include "../include/my.h"

char *find_reaction_name(char *line)
{
    char *name;
    char *tmp;
    int len = 0;

    tmp = my_strstr(line, "name=\"") + 6;
    for (; tmp != NULL && tmp[len] && tmp[len] != '"'; len++);
    name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tmp[i] && tmp[i] != '"'; i++)
        name[i] = tmp[i];
    name[len] = 0;
    return (name);
}

char *find_species_value(char *line)
{
    char *name;
    char *tmp;
    int len = 0;

    tmp = my_strstr(line, "species=\"\0") + 9;
    for (; tmp[len] && tmp[len] != '"'; len++);
    name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tmp[i] && tmp[i] != '"'; i++)
        name[i] = tmp[i];
    name[len] = 0;
    return (name);
}

char *find_comp_value(char *line)
{
    char *name;
    char *tmp;
    int len = 0;

    tmp = my_strstr(line, "compartment=\"\0") + 13;
    for (; tmp[len] && tmp[len] != '"'; len++);
    name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tmp[i] && tmp[i] != '"'; i++)
        name[i] = tmp[i];
    name[len] = 0;
    return (name);
}

char *find_reaction_id(char *line)
{
    char *name;
    char *tmp;
    int len = 0;

    tmp = my_strstr(line, "id=\"") + 4;
    for (; tmp[len] && tmp[len] != '"'; len++);
    name = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tmp[i] && tmp[i] != '"'; i++)
        name[i] = tmp[i];
    name[len] = 0;
    return (name);
}

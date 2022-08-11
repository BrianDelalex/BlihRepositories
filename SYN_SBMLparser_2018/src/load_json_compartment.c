/*
** EPITECH PROJECT, 2019
** load_json_compartment.c
** File description:
** load compartment in json format
*/

#include "../include/my.h"

comp_t *load_json_compartment(char **file, char *i_name)
{
    char *name = format_id_name(i_name);
    comp_t *comp = malloc(sizeof(comp_t));
    int *loc = NULL;

    loc = find_iname(name, file, loc);
    comp->id = i_name;
    comp->name = find_reaction_name(file[loc[0]]);
    if (comp->id == NULL || comp->name == NULL)
        return (NULL);
    return (comp);
}

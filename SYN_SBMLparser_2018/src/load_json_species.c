/*
** EPITECH PROJECT, 2019
** load_json_species.c
** File description:
** load species for json
*/

#include "../include/my.h"

spe_t *load_json_species(char **file, char *i_name)
{
    spe_t *spe = malloc(sizeof(spe_t));
    char *name = format_id_name(i_name);
    int *loc = NULL;

    loc = find_iname(name, file, loc);
    spe->comp = find_comp_value(file[loc[0]]);
    spe->id = i_name;
    spe->name = find_reaction_name(file[loc[0]]);
    if (spe->comp == NULL || spe->id == NULL || spe->name == NULL)
        return (NULL);
    return (spe);
}

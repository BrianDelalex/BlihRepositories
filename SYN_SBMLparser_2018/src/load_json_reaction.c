/*
** EPITECH PROJECT, 2019
** load_json_reaction.c
** File description:
** load reaction data for json
*/

#include "../include/my.h"

char *find_reversible_value(char *line)
{
    if (my_strstr(line, "false") != NULL)
        return ("false\0");
    else
        return ("true\0");
}

react_t *load_json_reaction(char **file, char *i_name)
{
    react_t *rea = malloc(sizeof(react_t));
    int *loc = NULL;
    char *name = format_species_name(i_name);

    loc = find_iname(name, file, loc);
    for (int i = 0; loc[0] - i > 0 ; i++)
        if (my_strstr(file[loc[0] - i], "<reaction") != NULL) {
            loc[0] = loc[0] - i;
            break;
        }
    rea->id = find_reaction_id(file[loc[0]]);
    rea->name = find_reaction_name(file[loc[0]]);
    rea->reversible = find_reversible_value(file[loc[0]]);
    if (my_strstr(file[loc[0]], "compartment=\0") != NULL)
        rea->comp = find_comp_value(file[loc[0]]);
    else
        rea->comp = NULL;
    if (rea->id == NULL || rea->name == NULL || rea->reversible == NULL)
        return (NULL);
    return (rea);
}

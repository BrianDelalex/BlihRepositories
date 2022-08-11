/*
** EPITECH PROJECT, 2019
** display_json_comp.c
** File description:
** display json when id is a compartment
*/

#include "../include/my.h"

int find_nb_of_species(char **file, char *name)
{
    int *loc = NULL;
    int len = 0;

    while (loc == NULL || loc[1] != -1) {
        loc = find_iname(name, file, loc);
        if (loc[1] == -1)
            break;
        if (my_strcmp("species" ,find_tag(file[loc[0]])))
            len++;
    }
    return (len);
}

void display_json_comp3(react_t *rea)
{
    if (rea == NULL)
        printf("]\n}\n");
    else {
        printf("],\n\"listOfReactions\": [\n    {\n      \"compartment\": ");
        printf("\"%s\",\n      \"id\": \"%s\",\n      \"name\": ", rea->comp,
        rea->id);
        printf("\"%s\",\n      \"reversible\": \"%s\"\n    }\n]\n}\n",
        rea->name, rea->reversible);
    }
}

void display_json_comp2(spe_t **spe, comp_t *comp, react_t *rea)
{
    printf("{\n\"listOfCompartments\": [\n    {\n");
    printf("      \"id\": \"%s\",\n", comp->id);
    printf("      \"name\": \"%s\"\n    }\n],\n", comp->name);
    printf("\"listOfSpecies\": [\n");
    for (int i = 0; spe[i]; i++) {
        printf("    {\n      \"compartment\": \"%s\",\n", spe[i]->comp);
        printf("      \"id\": \"%s\",\n", spe[i]->id);
        printf("      \"name\": \"%s\"\n", spe[i]->name);
        if (spe[i + 1] != NULL)
            printf("    },\n");
        else
            printf("    }\n");
    }
    display_json_comp3(rea);
}

react_t *take_react(char **file, char *name)
{
    int *loc = NULL;
    react_t *rea = malloc(sizeof(react_t));
    int ok = 0;

    while (loc == NULL || loc[1] != -1) {
        loc = find_iname("<reaction\0", file, loc);
        if (loc[1] == -1)
            break;
        if (my_strstr(file[loc[0]], "compartment=\"\0") != NULL) {
            ok = 1;
            break;
        }
    }
    if (ok == 1) {
        rea->comp = name;
        rea->id = find_reaction_id(file[loc[0]]);
        rea->name = find_reaction_name(file[loc[0]]);
        rea->reversible = find_reversible_value(file[loc[0]]);
        return (rea);
    }
    return (NULL);
}

void display_json_comp(char **file, char *i_name)
{
    comp_t *comp = NULL;
    char *name = my_strconcat("compartment=\"", i_name);
    int *loc = NULL;
    spe_t **spe;
    react_t *reac = take_react(file, i_name);
    int len = 0;

    comp = load_json_compartment(file, i_name);
    len = find_nb_of_species(file, name);
    spe = malloc(sizeof(spe_t *) * (len + 1));
    loc = NULL;
    for (int i = 0; loc == NULL || loc[1] != -1; i++) {
        loc = find_iname(name, file, loc);
        if (loc[1] == -1)
            break;
        spe[i] = load_json_species(file, find_reaction_id(file[loc[0]]));
    }
    spe[len] = NULL;
    display_json_comp2(spe, comp, reac);
}

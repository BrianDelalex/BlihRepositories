/*
** EPITECH PROJECT, 2019
** display_json_species.c
** File description:
** displays json if the id is a species
*/

#include "../include/my.h"

void display_json_species(char **file, char *i_name)
{
    json_t *json = create_json_struct();

    json->spe = load_json_species(file, i_name);
    json->comp = load_json_compartment(file, json->spe->comp);
    json->react = load_json_reaction(file, i_name);
    if (json->spe == NULL || json->comp == NULL || json->react == NULL)
        return;
    printf("{\n\"listOfCompartments\": [\n    {\n");
    printf("      \"id\": \"%s\",\n      \"name\": \"%s\"\n    }\n],\n",
    json->comp->id, json->comp->name);
    printf("\"listOfSpecies\": [\n    {\n      \"compartment\": ");
    printf("\"%s\",\n      \"id\": \"%s\",\n", json->spe->comp, json->spe->id);
    printf("      \"name\": \"%s\"\n    }\n],\n", json->spe->name);
    printf("\"listOfReactions\": [\n    {\n");
    if (json->react->comp != NULL)
        printf("      \"compartment\": \"%s\",\n", json->react->comp);
    printf("      \"id\": \"%s\",\n      \"name\": \"%s\",\n", json->react->id,
    json->react->name);
    printf("      \"reversible\": \"%s\"\n    }\n]\n}\n",
    json->react->reversible);
}

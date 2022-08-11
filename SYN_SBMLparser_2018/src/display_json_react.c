/*
** EPITECH PROJECT, 2019
** display_json_react.c
** File description:
** displays when json is on and a react past as arg
*/

#include "../include/my.h"

char **find_product(char **file, int *loc, char ***stoi)
{
    int *sted = malloc(sizeof(int) * 2);
    char **product;

    loc = find_iname("<listOfProducts>", file, loc);
    sted[0] = loc[0];
    loc = find_iname("</listOfProducts>", file, loc);
    sted[1] = loc[0];
    product = malloc(sizeof(char *) * (sted[1] - sted[0]));
    for (int i = 0; i < sted[1] - sted[0] - 1; i++) {
        product[i] = find_species_value(file[sted[0] + i + 1]);
        (*stoi) = add_str_to_tab(add_stoichio(file, sted[0] + i + 1), *stoi);
    }
    product[sted[1] - sted[0] - 1] = NULL;
    product = sort_tags(product);
    return (product);
}

char **find_reactant(char **file, int **loc, char ***stoi)
{
    int *sted = malloc(sizeof(int) * 2);
    char **reactant;

    *loc = find_iname("<listOfReactants>", file, *loc);
    sted[0] = (*loc)[0];
    *loc = find_iname("</listOfReactants>", file, *loc);
    sted[1] = (*loc)[0];
    reactant = malloc(sizeof(char *) * (sted[1] - sted[0]));
    for (int i = 0; i < sted[1] - sted[0] - 1; i++) {
        reactant[i] = find_species_value(file[sted[0] + i + 1]);
        *stoi = add_str_to_tab(add_stoichio(file, sted[0] + i + 1), *stoi);
    }
    reactant[sted[1] - sted[0] - 1] = NULL;
    reactant = sort_tags(reactant);
    return (reactant);
}

json_t *create_json_struct(void)
{
    json_t *json = malloc(sizeof(json_t));

    json->comp = NULL;
    json->spe = NULL;
    json->product = NULL;
    json->react = NULL;
    json->reactiv = NULL;
    return (json);
}

void display_json_rea(json_t *json, char **stoichio_prod, char **stoichio_react)
{
    printf("{\n\"listOfReactants\": [\n");
    for (int i = 0; json->reactiv[i]; i++) {
        printf("    {\n      \"species\": \"%s\",\n", json->reactiv[i]);
        printf("      \"stoichiometry\": \"%s\"\n    }", stoichio_react[i]);
        if (json->reactiv[i + 1] != NULL)
            printf(",\n");
        else
            printf("\n");
    }
    printf("],\n\"listOfProducts\": [\n");
    for (int i = 0; json->product[i]; i++) {
        printf("    {\n      \"species\": \"%s\",\n", json->product[i]);
        printf("      \"stoichiometry\": \"%s\"\n    }", stoichio_prod[i]);
        if (json->product[i + 1] != NULL)
            printf(",\n");
        else
            printf("\n");
    }
    printf("]\n}\n");
}

void display_json_react(char **file, char *i_name)
{
    int *loc = NULL;
    char *name = format_id_name(i_name);
    int ok = 0;
    char **stoichio_react = NULL;
    char **stoichio_prod = NULL;
    json_t *json = create_json_struct();


    while ((loc == NULL || loc[1] != -1) && ok != 1) {
        loc = find_iname(name, file, loc);
        if (loc[1] == -1)
            break;
        if (my_strcmp(find_tag(file[loc[0]]), "reaction"))
            ok = 1;
    }
    if (ok == 1) {
        json->reactiv = find_reactant(file, &loc, &stoichio_react);
        json->product = find_product(file, loc, &stoichio_prod);
        display_json_rea(json, stoichio_prod, stoichio_react);
    }
}

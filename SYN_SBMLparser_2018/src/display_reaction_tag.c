/*
** EPITECH PROJECT, 2019
** display_reaction_tag.c
** File description:
** display when the id is a reaction
*/

#include "../include/my.h"

char *add_stoichio(char **file, int loc)
{
    char *stoichio;
    char *tmp;
    int len = 0;

    tmp = my_strstr(file[loc], "stoichiometry=\"\0") + 15;
    for (; tmp[len] && tmp[len] != '"'; len++);
    stoichio = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tmp[i] && tmp[i] != '"'; i++)
        stoichio[i] = tmp[i];
    stoichio[len] = 0;
    return (stoichio);
}

void display_for_eflag(char **tab, int *sted, char **file, int reactant){
    for (int i = 0; i < sted[1] - sted[0] - 1; i++)
        tab[i] = my_strconcat(my_strconcat(
        add_stoichio(file, sted[0] + i + 1), " \0"), tab[i]);
    printf("%s ", tab[0]);
    for (int i = 1; tab[i]; i++)
        printf("+ %s", tab[i]);
    if (reactant == 1 && my_strstr(file[sted[0] - 1], "false"))
        printf(" -> ");
    else if (reactant == 1)
        printf(" <-> ");
    else
        printf("\n");
}

void display_product(int *loc, char **file, char const *i_name, int e)
{
    int *sted = malloc(sizeof(int) * 2);
    char **product;

    loc = find_iname("<listOfProducts>", file, loc);
    sted[0] = loc[0];
    loc = find_iname("</listOfProducts>", file, loc);
    sted[1] = loc[0];
    product = malloc(sizeof(char *) * (sted[1] - sted[0]));
    for (int i = 0; i < sted[1] - sted[0] - 1; i++)
        product[i] = find_species_value(file[sted[0] + i + 1]);
    product[sted[1] - sted[0] - 1] = NULL;
    product = sort_tags(product);
    if (e == 1)
        display_for_eflag(product, sted, file, 0);
    else {
        printf("List of products of reaction %s\n", i_name);
        for (int i = 0; product[i]; i++)
            printf("--->%s\n", product[i]);
    }
}

void display_reactant(int *loc, char **file, char const *i_name, int e)
{
    int *sted = malloc(sizeof(int) * 2);
    char **reactant;

    loc = find_iname("<listOfReactants>", file, loc);
    sted[0] = loc[0];
    loc = find_iname("</listOfReactants>", file, loc);
    sted[1] = loc[0];
    reactant = malloc(sizeof(char *) * (sted[1] - sted[0]));
    for (int i = 0; i < sted[1] - sted[0] - 1; i++)
        reactant[i] = find_species_value(file[sted[0] + i + 1]);
    reactant[sted[1] - sted[0] - 1] = NULL;
    reactant = sort_tags(reactant);
    if (e == 1)
        display_for_eflag(reactant, sted, file, 1);
    else {
        printf("List of reactants of reaction %s\n", i_name);
        for (int i = 0; reactant[i]; i++)
            printf("--->%s\n", reactant[i]);
    }
    display_product(loc, file, i_name, e);
}

void display_reaction_tag(char **file, char const *i_name, int e)
{
    int *loc = NULL;
    char *name = format_id_name(i_name);
    int ok = 0;

    while ((loc == NULL || loc[1] != -1) && ok != 1) {
        loc = find_iname(name, file, loc);
        if (loc[1] == -1)
            break;
        if (my_strcmp(find_tag(file[loc[0]]), "reaction"))
            ok = 1;
    }
    if (ok == 1)
        display_reactant(loc, file, i_name, e);
}

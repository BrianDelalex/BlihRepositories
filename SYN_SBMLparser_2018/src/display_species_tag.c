/*
** EPITECH PROJECT, 2019
** display_species_flag.c
** File description:
** displays when the id is a species id
*/

#include "../include/my.h"

species_t *create_species(char **file)
{
    species_t *spe = malloc(sizeof(species_t));
    int *loc = NULL;
    int *stnd = malloc(sizeof(int) * 2);

    spe->react = NULL;
    spe->stoichio = NULL;
    spe->reactions = NULL;
    spe->index = NULL;
    while (loc == NULL || loc[1] != -1) {
        loc = find_iname("<reaction\0", file, loc);
        if (loc[1] == -1)
            break;
        spe->reactions = add_str_to_tab
        (find_reaction_id(file[loc[0]]), spe->reactions);
        stnd[0] = loc[0];
        loc = find_iname("/reaction\0", file, loc);
        stnd[1] = loc[0];
        spe->index = add_int_list_to_tab(spe->index, stnd);
    }
    return (spe);
}

char *format_species_name(char const *i_name)
{
    char *name = malloc(sizeof(char) * (my_strlen(i_name) + 11));
    char comp[10] = "species=\"\0";

    for (int i = 0; comp[i]; i++)
        name[i] = comp[i];
    for (int i = 0; i_name[i]; i++)
        name[i + 9] = i_name[i];
    name[my_strlen(i_name) + 9] = '"';
    name[my_strlen(i_name) + 10] = 0;
    return (name);

}

int **find_stoichio(char **file, int *loc, int **tab)
{
    char *stoichio;
    char *tmp;
    int len = 0;
    int *new = malloc(sizeof(int));

    tmp = my_strstr(file[loc[0]], "stoichiometry=\"\0") + 15;
    for (; tmp[len] && tmp[len] != '"'; len++);
    stoichio = malloc(sizeof(char) * (len + 1));
    for (int i = 0; tmp[i] && tmp[i] != '"'; i++)
        stoichio[i] = tmp[i];
    stoichio[len] = 0;
    new[0] = my_getnbr(stoichio);
    return (add_int_list_to_tab(tab, new));
}

void find_reaction(species_t *spe, int *loc, char **file)
{
    for (int i = 0; spe->index[i]; i++) {
        if (loc[0] > spe->index[i][0] && loc[0] < spe->index[i][1]) {
            spe->react = add_str_to_tab(spe->reactions[i], spe->react);
            spe->stoichio = find_stoichio(file, loc, spe->stoichio);
        }
    }
}

void display_species_tag(char **file, char const *i_name)
{
    species_t *spe = create_species(file);
    char *name = format_species_name(i_name);
    int *loc = NULL;

    while ( loc == NULL || loc[1] != 1) {
        loc = find_iname(name, file, loc);
        if (loc[1] == -1)
            break;
        find_reaction(spe, loc, file);
    }
    printf("List of reactions consuming species %s (quantities)\n", i_name);
    for (int i = 0; spe->react[i]; i++) {
        printf("--->%s (%d)\n", spe->react[i],spe->stoichio[i][0]);
    }
}

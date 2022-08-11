/*
** EPITECH PROJECT, 2019
** display_compartment_tag.c
** File description:
** display if the id is a compartment tag
*/

#include "../include/my.h"

char *format_compartment_name(char *const i_name)
{
    char *name = malloc(sizeof(char) * (my_strlen(i_name) + 15));
    char comp[14] = "compartment=\"\0";

    for (int i = 0; comp[i]; i++)
        name[i] = comp[i];
    for (int i = 0; i_name[i]; i++)
        name[i + 13] = i_name[i];
    name[my_strlen(i_name) + 13] = '"';
    name[my_strlen(i_name) + 14] = 0;
    return (name);
}

char **get_names(char **lines)
{
    int len = 0;
    char **names;

    for (;lines[len]; len++);
    names = malloc(sizeof(char *) * (len + 1));
    names[len] = NULL;
    for (int i = 0; lines[i]; i++) {
        len = 0;
        lines[i] = my_strstr(lines[i], "name=\"") + 6;
        for (; lines[i][len] && lines[i][len] != '"'; len++);
        names[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; lines[i][j] && lines[i][j] != '"'; j++)
            names[i][j] = lines[i][j];
        names[i][len] = 0;
    }
    return (names);
}

void display_compartment_tag(char **const file, char *const i_name)
{
    char *name = format_compartment_name(i_name);
    int *loc = NULL;
    char **lines = NULL;
    char **names = NULL;

    while (loc == NULL || loc[1] != -1) {
        loc = find_iname(name, file, loc);
        if (loc[1] == -1)
            break;
        if (my_strcmp(find_tag(file[loc[0]]), "species"))
            lines = add_str_to_tab(file[loc[0]], lines);
    }
    names = get_names(lines);
    names = sort_tags(names);
    printf("List of species in compartment %s\n", i_name);
    for (int i = 0; names[i]; i++)
        printf("--->%s\n", names[i]);
}

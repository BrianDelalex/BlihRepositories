/*
** EPITECH PROJECT, 2019
** display_all_product.c
** File description:
** displays all products of the file
*/

#include "../include/my.h"

void display_all_product(char **file)
{
    int *loc = NULL;
    char **names = NULL;

    while (loc == NULL || loc[1] != 1) {
        loc = find_iname("<species \0", file, loc);
        if (loc[1] == -1)
            break;
        names = add_str_to_tab(find_reaction_name(file[loc[0]]), names);
    }
    names = sort_tags(names);
    printf("List of species\n");
    for (int i = 0; names[i]; i++)
        printf("--->%s\n", names[i]);
}

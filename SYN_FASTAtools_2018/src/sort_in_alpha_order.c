/*
** EPITECH PROJECT, 2019
** sort_in_alpha_order.c
** File description:
** sorts the list in alpha order
*/

#include "../include/my.h"

void compare2(char **tags, int i, int *i_min, char *c)
{
    int j = 0;

    for (; tags[i][j] && tags[*i_min][j]; j++) {
        if (tags[i][j] < tags[*i_min][j]) {
            *i_min = i;
            *c = tags[i][j];
            return;
        }
        if (tags[i][j] > tags[*i_min][j])
            return;
    }
    if (tags[i][j] == 0) {
        *i_min = i;
        *c = tags[i][j];
    }
}

void compare(char **tags, int i, int *i_min, char *min)
{
    if (tags[i][0] == *min)
        compare2(tags, i, i_min, min);
    if (tags[i][0] < *min) {
        *min = tags[i][0];
        *i_min = i;
    }
}

char **sort_tags(char **tags)
{
    char **sort = NULL;
    char min = 125;
    int i_min = 0;

    while (tags != NULL) {
        for (int i = 0; tags[i]; i++)
            compare(tags, i, &i_min, &min);
        if (tags[i_min] == NULL)
            break;
        sort = add_str_to_tab(tags[i_min], sort);
        tags = remove_str_to_tab(tags, i_min);
        i_min = 0;
        min = 125;
    }
    return (sort);
}

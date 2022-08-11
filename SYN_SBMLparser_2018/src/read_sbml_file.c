/*
** EPITECH PROJECT, 2019
** read_sbml_file.c
** File description:
** read the SBML file
*/

#include "../include/my.h"

int count_equal(char *ipt, list_t *list)
{
    int nb = 0;
    int len = 1;
    char *tag;

    for (int i = 0; ipt[i]; i++)
        if (ipt[i] == '=')
            nb = nb + 1;
    if (nb == 0)
        return (0);
    for (; ipt[len] && ipt[len] != 32; len++);
    tag = malloc(sizeof(char) * (len));
    for (int i = 1; ipt[i] && ipt[i] != 32; i++)
        tag[i - 1] = ipt[i];
    tag[len - 1] = 0;
    while (list != NULL) {
        if (my_strcmp(list->tag, tag) == 1)
            return (0);
        list = list->prev;
    }
    free(tag);
    return (nb);
}

char *save_tag(char *ipt, int *i)
{
    char *tag;
    int len = 1;

    for (; ipt[len] && ipt[len] != 32; len++);
    tag = malloc(sizeof(char) * (len));
    for (int j = 0; ipt[*i] && ipt[*i] != 32; *i = *i + 1, j++)
        tag[j] = ipt[*i];
    tag[len - 1] = 0;
    return (tag);
}

list_t *link_list(list_t *new, list_t *list)
{
    if (list == NULL)
        new->prev = NULL;
    else {
        new->prev = list;
        list->next = new;
    }
    new->next = NULL;
    list = new;
    return (list);
}

list_t *save_readed_info(char ***tags, list_t *list, char *ipt, int nb)
{
    int len = 1;
    char *tag;
    int i = 1;
    list_t *new = malloc(sizeof(list_t));

    tag = save_tag(ipt, &i);
    *tags = add_str_to_tab(tag, *tags);
    new->tag = my_strdup(new->tag, tag);
    new->attri = malloc(sizeof(char *) * (nb + 1));
    for (int j = 0 ; j < nb; j++) {
        i = i + 1;
        for (len = i; ipt[len] && ipt[len] != '='; len++);
        new->attri[j] = malloc(sizeof(char) * (len - i + 1));
        for (int k = 0; ipt[i] && ipt[i] != '='; i++, k++)
            new->attri[j][k] = ipt[i];
        for (int k = 0;ipt[i] && k < 2; i++)
            k = ipt[i] == '"' ? k + 1 : k;
    }
    return (link_list(new, list));
}

void read_sbml_file(list_t *list, FILE *file)
{
    char *input = NULL;
    char **tags = NULL;
    int nb = 0;

    input = use_getline(file);
    while (input != NULL) {
        free(input);
        input = use_getline(file);
        if (input == NULL)
            break;
        input = cut_repetitiv_char(input, 32);
        nb = count_equal(input, list);
        if (nb != 0)
            list = save_readed_info(&tags, list, input, nb);
    }
    for (; list->prev != NULL;)
        list = list->prev;
    display_list(sort_in_alpha_order(list, tags));
}

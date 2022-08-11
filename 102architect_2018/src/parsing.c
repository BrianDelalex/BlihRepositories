/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parses program entries
*/

#include "struct.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

t_vector *link_vector(t_vector *tmp, t_vector *list)
{
    if (list != NULL) {
        tmp->next = malloc(sizeof(t_vector));
        tmp->next = list;
    } else
        tmp->next = NULL;
    return (tmp);
}

t_vector *parsing2(char **av, t_vector *list, int ct, int ct2)
{
    t_vector *tmp;

    tmp = malloc(sizeof(t_vector));
    tmp->x = my_getnbr(av[ct2]);
    tmp->y = my_getnbr(av[ct2 + 1]);
    tmp->transfo = av[ct][1];
    if (av[ct][1] == 't')
        printf("Translation along vector (%d, %d)\n", tmp->x, tmp->y);
    else
        printf("Scaling by factors %d and %d\n", tmp->x, tmp->y);
    tmp = create_matrix(tmp);
    tmp = link_vector(tmp, list);
    list = tmp;
    return (list);
}

t_vector *parsing3(char **av, t_vector *list, int ct, int ct2)
{
    t_vector *tmp;

    tmp = malloc(sizeof(t_vector));
    tmp->x = my_getnbr(av[ct2]);
    tmp->transfo = av[ct][1];
    tmp = create_matrix(tmp);
    if (av[ct][1] == 'r')
        printf("Rotation by a %d degree angle\n", tmp->x);
    else
        printf("Reflection over an axis with an inclination angle of %d \
degrees\n", tmp->x);
    tmp = link_vector(tmp, list);
    list = tmp;
    return (list);
}

t_vector *handle_multi_tranform_flag(char **av, t_vector *list, int *ct)
{
    switch (list->transfo) {
        case 'z':
        case 't':
            list = parsing2(av, list, find_previous_flag_index(av ,*ct), *ct);
            *ct = *ct + 2;
        case 's':
        case 'r':
            list = parsing3(av, list, find_previous_flag_index(av ,*ct), *ct);
            *ct = *ct + 1;
        default:
            break;
    }
    return (list);
}

t_vector *parsing(int ac, char **av)
{
    t_vector *list = 0;
    int ct = 3;

    ac = ac - 1;
    while (ct <= ac) {
        switch(av[ct][1]) {
            case 'z':
            case 't':
                list = parsing2(av, list, ct, ct + 1);
                ct = ct + 3;
                break;
            case 's':
            case 'r':
                list = parsing3(av, list, ct, ct + 1);
                ct = ct + 2;
                break;
            default:
                list = handle_multi_tranform_flag(av, list, &ct);
        }
    }
    return (list);
}

/*
** EPITECH PROJECT, 2018
** create_list.c
** File description:
** creates list from arguments
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

t_list *create_list(int ac, char **av, t_control *control)
{
    t_list *list = NULL;
    t_list *tmp;

    ac -= 1;
    control->size_l_a = ac;
    control->low = my_getnbr(av[ac]);
    for (; ac > 0; ac--) {
        tmp = malloc(sizeof(t_list));
        tmp->nb = my_getnbr(av[ac]);
        if (tmp->nb < control->low)
            control->low = tmp->nb;
        if (list != NULL)
            tmp->next = list;
        else {
            tmp->next = NULL;
            control->l_a_end = tmp;
        }
        list = tmp;
    }
    control->l_a_end->next = list;
    return (list);
}

/*
** EPITECH PROJECT, 2018
** operation2.c
** File description:
** operation for pushswap project
*/

#include "struct.h"
#include <stdlib.h>
#include "my.h"

void ra(t_control *control)
{
    control->l_a_end = control->l_a;
    control->l_a = control->l_a->next;
    control->display = add_char_to_char("ra \0", control->display);
}

void rb(t_control *control)
{
    control->l_b = control->l_b->next;
    control->display = add_char_to_char("rb \0", control->display);
}

void rr(t_control *control)
{
    ra(control);
    rb(control);
}

void rra(t_control *control)
{
    t_list *tmp = control->l_a;
    t_list *tmp2;
    if (tmp->next != NULL && tmp != NULL) {
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        tmp2 = tmp->next;
        tmp->next = NULL;
        tmp2->next = control->l_a;
        control->l_a = tmp2;
    }
    control->display = add_char_to_char("rra\0 ", control->display);
}

void rrb(t_control *control)
{
    t_list *tmp = control->l_b;
    t_list *tmp2;

    while (tmp->next->next != NULL)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = NULL;
    tmp2->next = control->l_b;
    control->l_b = tmp2;
    control->display = add_char_to_char("rrb\0 ", control->display);
}

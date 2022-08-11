/*
** EPITECH PROJECT, 2018
** operation.c
** File description:
** operation on str for push_swap
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

void sc(t_control *control)
{
    sa(control->l_a, control, 'a');
    sa(control->l_b, control, 'b');
}

void sa(t_list *list, t_control *control, char c)
{
    t_list *tmp;
    t_list *tmp2;

    if (list != NULL && list->next != NULL) {
        tmp = list;
        tmp2 = list->next->next;
        list = list->next;
        list->next = tmp;
        list->next->next = tmp2;
    }
    if (c == 'a') {
        control->l_a = list;
        control->display = add_char_to_char("sa \0", control->display);
    } else {
        control->l_b = list;
        control->display = add_char_to_char("sb \0", control->display);
    }
}

void pa(t_control *control)
{
    t_list *tmp;

    tmp = control->l_b;
    control->l_b = control->l_b->next;
    tmp->next = control->l_a;
    control->l_a = tmp;
    control->l_a_end->next = control->l_a;
    control->size_l_b--;
    control->size_l_a++;
    control->display = add_char_to_char("pa \0", control->display);
}

void pb(t_control *control)
{
    t_list *tmp;

    tmp = control->l_a;
    control->l_a = control->l_a->next;
    control->l_a_end->next = control->l_a;
    tmp->next = control->l_b;
    control->l_b = tmp;
    control->size_l_a = control->size_l_a - 1;
    control->size_l_b = control->size_l_b + 1;
    control->display = add_char_to_char("pb \0", control->display);
}

void rrr(t_control *control)
{
    ra(control);
    rb(control);
}

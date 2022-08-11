/*
** EPITECH PROJECT, 2018
** sorting.c
** File description:
** sorts list
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

void display_operation(t_control *control)
{
    int len = my_strlen(control->display);

    control->display[len - 1] = '\n';
    my_putstr(control->display);
}

void sorting(t_control *control)
{
    int new_low = control->l_a->nb;
    t_list *tmp;

    while (control->size_l_a > 1) {
        for (; control->l_a->nb != control->low; ra(control));
        pb(control);
        if (control->size_l_a == 1)
            break;
        new_low = control->l_a->nb;
        tmp = control->l_a;
        for (int i = 1; i < control->size_l_a; i++) {
            new_low = tmp->nb < new_low ? tmp->nb : new_low;
            tmp = tmp->next;
        }
        control->low = new_low;
    }
    while (control->size_l_b > 0)
        pa(control);
    display_operation(control);
}

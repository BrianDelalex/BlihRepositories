/*
** EPITECH PROJECT, 2018
** print_list.c
** File description:
** prints list content
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>

void print_list(t_list *list, char c)
{
    t_list *tmp = list;

    my_putchar(c);
    my_putstr(":");
    while (tmp != NULL) {
        my_putstr(" ");
        my_putnbr(tmp->nb);
        my_putstr(",");
        tmp = tmp->next;
    }
    my_putstr("\n");
}

/*
** EPITECH PROJECT, 2018
** my_rev_list.c
** File description:
** reverses a list
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

int my_listlen(t_vector *list)
{
    t_vector *tmp = list;
    int i = 0;

    while (tmp != NULL) {
        i = i + 1;
        tmp = tmp->next;
    }
    free(tmp);
    return (i);
}

t_vector *my_rev_list(t_vector *list)
{
    t_vector *swap = 0;
    t_vector *swap2 = 0;
    t_vector *tmp = 0;
    int len = my_listlen(list);

    tmp = list;
    swap = tmp->next;
    tmp->next = NULL;
    for (int i = 0; i < len - 1; i = i + 1) {
        swap2 = tmp;
        tmp = swap;
        swap = tmp->next;
        tmp->next = swap2;
    }
    list = tmp;
    return (list);
}

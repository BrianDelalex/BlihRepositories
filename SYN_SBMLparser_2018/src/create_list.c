/*
** EPITECH PROJECT, 2019
** create_list.c
** File description:
** creates list
*/

#include "../include/my.h"

list_t *create_list(int len)
{
    list_t *list = NULL;
    list_t *new;

    for (int i = 0; i <= len; i++) {
        new = malloc(sizeof(list_t));
        if (list == NULL)
            new->prev = NULL;
        else {
            new->prev = list;
            list->next = new;
        }
        new->next = NULL;
        list = new;
    }
    while (list->prev != NULL)
        list = list->prev;
    return (list);
}

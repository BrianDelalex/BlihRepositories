/*
** EPITECH PROJECT, 2019
** clientList_manager.c
** File description:
** manage clientList_t
*/

#include "utils/list.h"

void list_free(list_t *list)
{
    list_t *tmp = list->next;

    while (list != NULL) {
        tmp = list->next;
        free(list->item);
        free(list);
        list = tmp;
    }
}
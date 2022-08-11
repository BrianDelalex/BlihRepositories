/*
** EPITECH PROJECT, 2019
** clientList_manager.c
** File description:
** manage clientList_t
*/

#include <stdio.h>

#include "utils/list.h"

list_t *list_init()
{
    list_t *list = calloc(sizeof(list_t), 1);

    list->next = NULL;
    list->item = NULL;
    return (list);
}

list_t *list_add_node(list_t *list, void *item)
{
    list_t *node;
    list_t *tmp;
    
    if (list == NULL)
        return (NULL);
    if (list->item ==  NULL) {
        list->item = item;
        list->next = NULL;
        return (list);
    }
    node = calloc(sizeof(list_t), 1);
    node->item = item;
    node->next = NULL;
    for (tmp = list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
    return (list);
}

list_t *list_find_node(list_t *list, void *item)
{
    list_t *tmp;

    for (tmp = list; tmp != NULL && item != tmp->item; tmp = tmp->next);
    if (tmp == NULL)
        return (NULL);
    return (tmp);
}

int list_get_lenght(list_t *list)
{
    list_t *tmp;
    int i = 0;

    for (tmp = list; tmp != NULL; tmp = tmp->next, i++);
    return (i);
}

list_t *list_remove_node(list_t *list, list_t *rm)
{
    list_t *tmp = list;
    
    if (rm == list) {
        tmp = list->next;
        free(list->item);
        free(list);
        return (tmp);
    }
    for(; tmp->next != rm; tmp = tmp->next);
    if (tmp == NULL)
        return (list);
    tmp->next = rm->next;
    free(rm->item);
    free(rm);
    return (list);
}
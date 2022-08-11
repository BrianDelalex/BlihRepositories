/*
** EPITECH PROJECT, 2019
** display_list.c
** File description:
** displays list
*/

#include "../include/my.h"

void display_list(list_t *list)
{
    while (list->next != NULL) {
        printf("%s\n", list->tag);
        for (int i = 0; list->attri[i]; i++)
            printf("--->%s\n", list->attri[i]);
        list = list->next;
    }
}

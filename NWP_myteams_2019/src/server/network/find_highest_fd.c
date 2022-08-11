/*
** EPITECH PROJECT, 2019
** find_highest_fd.c
** File description:
** find the highest fd open
*/

#include "server/network/network.h"

int find_highest_fd(list_t *clients, int sock)
{
    int highest = 0;

    for (list_t *tmp = clients; tmp != NULL; tmp = tmp->next) {
        if (tmp->item && *((int *) tmp->item) > highest)
            highest = *((int *) tmp->item);
    }
    if (highest < sock)
        highest = sock;
    return (highest);
}
/*
** EPITECH PROJECT, 2019
** set_current_user_from_fd.c
** File description:
** set the current user from fd
*/

#include "server/context.h"
#include "server/network/network.h"

void set_current_user_from_fd(int sock)
{
    list_t *tmp = context->users;

    for (; tmp != NULL && tmp->item != NULL && ((struct user_t *)tmp->item)->fd != sock; tmp = tmp->next);
    if (tmp && tmp->item) {
        context->active = ((struct user_t *)tmp->item);
        return;
    }
}
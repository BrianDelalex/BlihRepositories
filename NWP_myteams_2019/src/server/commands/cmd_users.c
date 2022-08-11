/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include "server/context.h"
#include "server/data/users.h"
#include <stdio.h>

void send_user(struct user_t *user, int client)
{
    write(client, ((void *) user), sizeof(struct user_t));
}

void cmd_users(const char **msg __unused, int client)
{
    char eot[2];
    eot[0] = 4;
    eot[1] = 0;
    if (!context->active || (context->active && \
    context->active->connected == false)) {
        write(client, eot, 2);
        return;
    }
    for (list_t *tmp = context->users; tmp != NULL; tmp = tmp->next) {
        if (tmp->item)
            send_user(((struct user_t *) tmp->item), client);
    }
    write(client, eot, 2);
}

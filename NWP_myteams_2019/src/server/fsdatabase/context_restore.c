/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/context.h"
#include "myteams/logging_server.h"
#include "server/fsdatabase/model.h"
#include "def/typedef.h"
#include "def/macro.h"
#include <stdint.h>
#include <unistd.h>

void context_restore(void)
{
    struct user_t *user;
    int fd = open(FSDATABASE_DATA, O_RDONLY);

    if (!fd)
        return;
    while (1) {
        user = calloc(sizeof(struct user_t), 1);
        if (read(fd, user, sizeof(struct user_t)) != sizeof(struct user_t))
            break;
        list_add_node(context->users, (void *)user);
        server_event_user_loaded(user->uuid, user->name);
        user->connected = false;
        user->fd = -1;
    }
    free(user);
}
/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "server/data/users.h"
#include "server/context.h"
#include "myteams/logging_server.h"
#include "utils/list.h"
#include "utils/protocol.h"
#include "def/macro.h"
#include <string.h>

void broadcast(char const *code, char const *uuid, char const *name)
{
    list_t *users = context->users;
    struct user_t *user;
    char *msg;

    while (users) {
        user = users->item;
        if (user->fd == -1 ) {
            users = users->next;
            continue;
        }
        msg = calloc(sizeof(char), strlen(user->uuid) + strlen(user->name) + 
        strlen(code) + 2);
        msg = strcpy(msg, code);
        msg = strcat(msg, uuid);
        msg = strcat(msg, " ");
        msg = strcat(msg, name);
        write(user->fd, msg, strlen(msg) + 1);
        free(msg);
        users = users->next;
    }
}

list_t *user_getptr_from_uuid(char const *uuid)
{
    list_t *item = context->users;

    while (item && item->item) {
        if (!strcmp(((struct user_t *)item->item)->uuid, uuid))
            return (item);
        item = item->next;
    }
    return (NULL);
}

list_t *user_getptr_from_fd(int fd)
{
    list_t *item = context->users;

    while (item && item->item) {
        if (((struct user_t *)item->item)->fd == fd)
            return (item);
        item = item->next;
    }
    return (NULL);
}
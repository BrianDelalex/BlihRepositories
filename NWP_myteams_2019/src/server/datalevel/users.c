/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/data/users.h"
#include "server/context.h"
#include "myteams/logging_server.h"
#include "utils/list.h"
#include "utils/protocol.h"
#include "def/macro.h"
#include <string.h>

list_t *user_getptr_from_name(char const *uuid)
{
    list_t *item = context->users;

    while (item && item->item) {
        if (!strcmp(((struct user_t *)item->item)->name, uuid))
            return (item);
        item = item->next;
    }
    return (NULL);
}

struct user_t *user_create(char const *name)
{
    struct user_t *item;

    item = vmalloc(sizeof(struct user_t));
    item->connected = false;
    strcpy(item->name, name);
    strcpy(item->uuid, uuid_new());
    memset(&(item->context), 0x0, sizeof(struct usercontext_t));
    item->fd = -1;
    list_add_node(context->users, item);
    return (item);
}

bool user_remove(char const *uuid)
{
    list_t *user = user_getptr_from_name(uuid);
    
    if (!user)
        return (false);
    context->users = list_remove_node(context->users, user);
    return (true);
}

bool user_connect(char const *uuid, int fd)
{
    list_t *list = user_getptr_from_name(uuid);
    list_t *list2 = user_getptr_from_fd(fd);
    struct user_t *user;
    char eot[2];

    eot[0] = 4;
    eot[1] = 0;
    if (list2) {
        write(fd, eot, 2);
        return (true);
    }
    if (!list) {
        user = user_create(uuid);
        server_event_user_created(user->uuid, user->name);
    } else
        user = list->item;
    user->fd = fd;
    user->connected = true;
    context->active = user;
    server_event_user_logged_in(user->uuid);
    broadcast(USR_CON, user->uuid, user->name);
    return (true);
}

bool user_disconnect(char const *uuid)
{
    list_t *list = user_getptr_from_name(uuid);
    struct user_t *user;

    if (!list)
        return (false);
    else
        user = list->item;
    server_event_user_logged_out(user->uuid);
    user->connected = false;
    broadcast(USR_DSC, user->uuid, user->name);
    user->fd = -1;
    return (true);
}

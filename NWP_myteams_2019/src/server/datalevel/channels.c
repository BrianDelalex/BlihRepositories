/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/data/channels.h"
#include "server/context.h"
#include "utils/list.h"
#include "def/macro.h"
#include <string.h> 

list_t *channel_getptr_from_uuid(list_t *channel, char const *uuid)
{
    list_t *item = channel;

    while (item && item->item) {
        if (!strcmp(((struct channel_t *)item->item)->name, uuid))
            return (item);
        item = item->next;
    }
    return (NULL);
}

bool channel_create(char const *channel, char const *desc)
{
    struct team_t *teamptr = context->active->context.team;
    struct channel_t *channelptr;

    if (!teamptr)
        return (false);
    channelptr = vmalloc(sizeof(struct channel_t));
    channelptr->name = strdup(channel);
    channelptr->parent = teamptr;
    channelptr->desc = strdup(desc);
    channelptr->threads = list_init();
    list_add_node(teamptr->channels, channelptr);
    return (true);
}

bool channel_remove(char const *channel)
{
    struct team_t *teamptr = context->active->context.team;
    list_t *channelptr;
    
    if (!teamptr)
        return (false);
    channelptr = channel_getptr_from_uuid(teamptr->channels, channel);
    if (!channelptr)
        return (false);
    teamptr->channels = list_remove_node(teamptr->channels, channelptr);
    return (true);
}
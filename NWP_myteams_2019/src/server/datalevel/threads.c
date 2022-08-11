/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/data/threads.h"
#include "server/data/teams.h"
#include "server/data/channels.h"
#include "server/context.h"
#include "utils/list.h"
#include "def/macro.h"
#include <string.h> 

list_t *thread_getptr_from_uuid(list_t *channel, char const *uuid)
{
    list_t *item = channel;

    while (item && item->item) {
        if (!strcmp(((struct thread_t *)item->item)->name, uuid))
            return (item);
        item = item->next;
    }
    return (NULL);
}

bool thread_create(char const *thread, char const *msg)
{
    struct thread_t *threadptr;

    if (!context->active->context.channel)
        return (false);
    threadptr = vmalloc(sizeof(struct thread_t));
    threadptr->name = strdup(thread);
    threadptr->comment = list_init();
    threadptr->provider = context->active;
    threadptr->basemsg = strdup(msg);
    threadptr->parent = context->active->context.channel;
    list_add_node(threadptr->parent->threads, threadptr);
    return (true);
}

bool thread_create_comment(char const *msg)
{
    struct comment_t *item;

    if (!context->active->context.thread)
        return (false);
    item = vmalloc(sizeof(struct comment_t));
    item->writer = context->active;
    item->msg = strdup(msg);
    item->parent = context->active->context.thread;
    list_add_node(item->parent->comment, item);
    return (true);
}

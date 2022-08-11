/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/data/users.h"
#include "server/context.h"
#include "utils/list.h"
#include "def/macro.h"
#include <string.h> 

static bool user_enter_team(char const *uuid)
{
    struct team_t *team = team_getptr_from_uuid(uuid)->item;

    if (!team)
        return (false);
    context->active->context.team = team;
    return (true);
}

static bool user_enter_channel(char const *uuid)
{
    struct channel_t *channel = channel_getptr_from_uuid(
    context->active->context.team->channels, uuid)->item;

    if (!channel)
        return (false);
    context->active->context.channel = channel;
    return (true);
}

static bool user_enter_thread(char const *uuid)
{
    struct thread_t *thread = thread_getptr_from_uuid(
    context->active->context.channel->threads, uuid)->item;

    if (!thread)
        return (false);
    context->active->context.thread = thread;
    return (true);
}

static bool user_reset(void)
{
    memset(&(context->active->context), 0x0, sizeof(struct datacontext_t));
    return (true);
}

bool user_change_context(char const *uuid)
{
    if (!uuid)
        return (user_reset());
    if (!context->active->context.team)
        return (user_enter_team(uuid));
    if (context->active->context.team && 
    !context->active->context.channel)
        return (user_enter_channel(uuid));
    if (context->active->context.team &&
    context->active->context.channel &&
    !context->active->context.thread)
        return (user_enter_thread(uuid));
    return (false);
}
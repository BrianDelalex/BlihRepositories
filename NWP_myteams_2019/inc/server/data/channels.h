/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef _CHANNELS_H__
#define _CHANNELS_H__

#include "server/data/users.h"
#include "server/data/teams.h"
#include "server/data/threads.h"
#include "utils/list.h"

struct channel_t
{
    char *name;
    char const *desc;
    list_t *threads;
    struct team_t *parent;
};

list_t *channel_getptr_from_uuid(list_t *channel, char const *uuid);
bool channel_create(char const *channel, char const *desc);
bool channel_remove(char const *channel);

#endif
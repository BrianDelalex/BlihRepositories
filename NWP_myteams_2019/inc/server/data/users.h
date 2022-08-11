/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef _USERS_H__
#define _USERS_H__

#include <stdbool.h>
#include "utils/list.h"
#include "server/data/users.h"
#include "server/data/channels.h"
#include "server/data/teams.h"
#include "server/data/threads.h"

struct usercontext_t
{
    struct team_t    *team;
    struct channel_t *channel;
    struct thread_t  *thread;
};

struct directmsg_t
{
    struct user_t *writer;
    char const *data;
};

struct user_t
{
    char name[32];
    char uuid[37];
    int  fd;
    struct usercontext_t context;
    bool connected;
};

list_t *user_getptr_from_name(char const *uuid);
list_t *user_getptr_from_uuid(char const *uuid);
bool user_change_context(char const *uuid);
struct user_t *user_create(char const *name);
bool user_remove(char const *uuid);
bool user_connect(char const *uuid, int fd);
bool user_disconnect(char const *uuid);
void broadcast(char const *code, char const *uuid, char const *name);
list_t *user_getptr_from_fd(int fd);

#endif
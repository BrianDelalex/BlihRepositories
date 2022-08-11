/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef _THREADS_H__
#define _THREADS_H__

#include "server/data/users.h"
#include "server/data/channels.h"

struct comment_t
{
    struct user_t *writer;
    char const *msg;
    struct thread_t *parent;
};

struct thread_t
{
    char *name;
    struct user_t *provider;
    char const *basemsg;
    list_t *comment;
    struct channel_t *parent;
};

list_t *thread_getptr_from_uuid(list_t *thread, char const *uuid);
bool thread_create_comment(char const *msg);
bool thread_create(char const *thread, char const *msg);

#endif
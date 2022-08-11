/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef _CONTEXT_H__
#define _CONTEXT_H__

#include "server/data/users.h"
#include "server/data/threads.h"
#include "server/data/channels.h"
#include "server/data/teams.h"
#include "utils/list.h"

struct datacontext_t
{
    list_t *users;
    list_t *teams;
    struct user_t *active;
};

extern struct datacontext_t *context;

char const *uuid_new(void);

void context_init(void);
void context_exit(int);

void context_restore(void);
void context_save(void);

#endif
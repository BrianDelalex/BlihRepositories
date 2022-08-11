/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef _TEAMS_H__
#define _TEAMS_H__

#include "server/data/users.h"

struct team_t
{
    char *name;
    char const *uuid;
    char const *desc;
    list_t *channels;
    list_t *users;
};

list_t *team_getptr_from_uuid(char const *uuid);
void team_create(char const *name, char const *desc);
bool team_remove(char const *uuid);
bool team_join_user(char const *team, char const *user);
bool team_leave_user(char const *team, char const *user);
bool team_is_user_in(char const *user);
bool team_is_channel_in(char const *channel);

#endif
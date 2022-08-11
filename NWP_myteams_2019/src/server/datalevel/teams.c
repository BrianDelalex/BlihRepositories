/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/data/teams.h"
#include "server/context.h"
#include "utils/list.h"
#include "def/macro.h"
#include <string.h> 

list_t *team_getptr_from_uuid(char const *uuid)
{
    list_t *item = context->teams;

    while (item && item->item) {
        if (!strcmp(((struct team_t *)item->item)->name, uuid))
            return (item);
        item = item->next;
    }
    return (NULL);
}

void team_create(char const *name, char const *desc)
{
    struct team_t *item = vmalloc(sizeof(struct team_t));
    
    item->name = strdup(name);
    item->desc = strdup(desc);
    item->uuid = uuid_new();
    list_add_node(context->teams, item);
}

bool team_remove(char const *uuid)
{
    list_t *team = team_getptr_from_uuid(uuid);
    
    if (!team)
        return (false);
    context->teams = list_remove_node(context->teams, team);
    return (true);
}

bool team_join_user(char const *ch_uuid, char const *ur_uuid)
{
    list_t *teamnode = team_getptr_from_uuid(ch_uuid);
    list_t *usernode = user_getptr_from_name(ur_uuid);
    
    if (!teamnode || !usernode)
        return (false);
    struct team_t *team = teamnode->item;
    struct user_t *user = usernode->item;
    list_add_node(team->users, user);
    return (true);
}

bool team_leave_user(char const *ch_uuid, char const *ur_uuid)
{
    list_t *teamnode = team_getptr_from_uuid(ch_uuid);
    list_t *user = user_getptr_from_name(ur_uuid);

    if (!teamnode)
        return (false);
    struct team_t *team = teamnode->item;
    team->users = list_remove_node(team->users, user);
    return (true);
}
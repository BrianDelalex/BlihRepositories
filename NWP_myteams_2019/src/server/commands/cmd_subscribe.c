/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include "server/data/teams.h"
#include "server/context.h"
#include <stdio.h>

void cmd_subscribe(const char **msg, int client __unused)
{ 
    int len = lentab(msg);
    

    if (len != 2)
        return;
    team_join_user(msg[1], context->active->name);
}
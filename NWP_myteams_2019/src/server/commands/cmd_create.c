/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include "server/context.h"
#include <stdio.h>

void cmd_create(const char **msg __unused, int client __unused)
{
    int len = lentab(msg);

    if (context->active->context.thread && len == 2)
        thread_create_comment(msg[1]);
    else if (context->active->context.channel && len == 3)
        thread_create(msg[1], msg[2]);
    else if (context->active->context.team && len == 3)
        channel_create(msg[1], msg[2]);
    else if (!context->active->context.team && len == 3)
        team_create(msg[1], msg[2]);
}
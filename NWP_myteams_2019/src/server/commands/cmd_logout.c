/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include "server/data/users.h"
#include "server/context.h"
#include <unistd.h>
#include <stdio.h>

void cmd_logout(const char **msg __unused, int client __unused)
{
    if (context->active) {
        user_disconnect(context->active->name);
    }
}
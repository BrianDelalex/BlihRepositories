/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include "server/data/users.h"

void cmd_use(const char **msg __unused, int client __unused)
{
    int len = lentab(msg);

    if (len != 2)
        return;
    user_change_context(msg[1]);
}
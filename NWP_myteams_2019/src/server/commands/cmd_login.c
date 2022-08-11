/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include "server/data/users.h"
#include <stdio.h>

void cmd_login(const char **msg, int client)
{ 
    int len = lentab(msg);

    if (len != 2)
        return;
    user_connect(msg[1], client);
}

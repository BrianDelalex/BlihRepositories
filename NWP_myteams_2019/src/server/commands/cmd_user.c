/*
** EPITECH PROJECT, 2019
** myteams
** File description:
** I am dying inside
*/

#include "server/commands/commands.h"
#include <stdio.h>

void cmd_user(const char **msg __unused, int client __unused)
{ 
    struct user_t *user;
    list_t *list = user_getptr_from_uuid(msg[1]);
    char eot[2];
    int len = lentab(msg);

    eot[0] = 4;
    eot[1] = 0;
    if (len != 2 || !list ||(user = list->item) == NULL) {
        write(client, eot, 2);
        return;
    }
    write(client, ((void *)user), sizeof(struct user_t));
}
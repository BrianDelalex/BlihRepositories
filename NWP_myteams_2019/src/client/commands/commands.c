/*
** EPITECH PROJECT, 2019
** commands.c
** File description:
** Functions corresponding to command.
*/

#include "client/commands/commands.h"
#include "utils/str_to_tab.h"
#include "myteams/logging_client.h"
#include "server/data/users.h"


void cmd_help(__attribute__((unused))int *sock)
{
    printf("cmd function help\n");
}

void cmd_login(int *sock)
{
    char *buf = calloc(sizeof(char), 1024);
    char eof[2];

    eof[0] = 4;
    eof[1] = 0;
    if (read(*sock, buf, 1024) == -1)
    {
        free(buf);
        return;
    }
    if (strncmp(buf, eof, 2) == 0) {
        client_error_unauthorized();
        free(buf);
        return;
    }
    buf = buf + 1;
    char **strtab = str_to_tab(buf);
    client_event_loggedin(strtab[0], strtab[1]);
}

void cmd_logout(__attribute__((unused))int *sock)
{
}

void cmd_users(int *sock)
{
    char *msg = vmalloc(sizeof(struct user_t) + 1);
    struct user_t *user;
    msg[0] = 0;
    

    while (1) {
        if (read(*sock, msg, sizeof(struct user_t)) == -1)
        {
            free(msg);
            return;
        }
        if (msg[0] == 4) {
            free(msg);
            return;
        }
        user = ((struct user_t *) msg);
        client_print_users(user->uuid, user->name, user->connected);
        free(msg);
        msg = vmalloc(sizeof(struct user_t) + 1);
    }
}

void cmd_user(__attribute__((unused))int *sock)
{
    char *msg = malloc(sizeof(struct user_t) + 1);
    struct user_t *user;

    if (!msg)
        return;
    if ( read(*sock, msg, sizeof(struct user_t)) == -1)
    {
        free(msg);
        return;
    }
    if (msg[0] == 4) {
        free(msg);
        return;
    }
    user = (struct user_t *) msg;
    client_print_user(user->uuid, user->name, user->connected);
    free(msg);
    return;
}
/*
** EPITECH PROJECT, 2019
** command_handler.c
** File description:
** command handler
*/

#include "client/interpreter/command_handler.h"

static struct cmd_handler_s cmd_handler =
{
    .msg = {
        "/help",
        "/login",
        "/logout",
        "/users",
        "/user",
        "/send",
        "/messages",
        "/subscribe",
        "/subscribed",
        "/unsubscribe",
        "/use",
        "/create",
        "/list",
        "/info",
        NULL,
    },
    .handler = {
        cmd_help,
        cmd_login,
        cmd_logout,
        cmd_users,
        cmd_user,
        cmd_send,
        cmd_messages,
        cmd_subscribe,
        cmd_subscribed,
        cmd_unsubscribe,
        cmd_use,
        cmd_create,
        cmd_list,
        cmd_info,
        NULL
    }
};

void *getHandlerFromCmd(char *msg)
{
    void *handler = NULL;

    for (unsigned int i = 0; cmd_handler.msg[i]; i++) {
        if (!strncmp(msg, cmd_handler.msg[i], strlen(cmd_handler.msg[i]))) {
            handler = ((void *)cmd_handler.handler[i]);
            break;
        }
    }
    return (handler);
}


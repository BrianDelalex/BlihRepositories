/*
** EPITECH PROJECT, 2019
** command_handler.c
** File description:
** command handler
*/

#include "server/commands/commands.h"
#include "server/interpreter/command_handler.h"
#include <stdio.h>
#include <string.h>

static struct cmd_handler_t cmd_handler =
{
    .msg = {
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
        NULL
    },
    .handler = {
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

bool command_handler(const char *msg, int client)
{
    size_t len;
    char const **div;

    for (int i = 0; cmd_handler.msg[i]; i++) {
        len = strlen(cmd_handler.msg[i]);
        if (strlen(msg) < len)
            continue;
        if (!strncmp(msg, cmd_handler.msg[i], len)) {
            div = (char const **)str_to_tab(msg);
            cmd_handler.handler[i](div, client);
            free_tab(div);
            return (true);
        }
    }
    return (false);
}
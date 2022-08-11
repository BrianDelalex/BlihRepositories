/*
** EPITECH PROJECT, 2019
** command_handler.h
** File description:
** command handler header
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

# include "unistd.h"

# include "def/keyword.h"
# include "def/typedef.h"
# include "server/interpreter/command_handler.h"
# include "server/data/users.h"

void cmd_login(const char **msg, int client);
void cmd_logout(const char **msg, int client);
void send_user(struct user_t *user, int client);
void cmd_users(const char **msg, int client);
void cmd_user(const char **msg, int client);
void cmd_send(const char **msg, int client);
void cmd_messages(const char **msg, int client);
void cmd_subscribe(const char **msg, int client);
void cmd_subscribed(const char **msg, int client);
void cmd_unsubscribe(const char **msg, int client);
void cmd_use(const char **msg, int client);
void cmd_create(const char **msg, int client);
void cmd_list(const char **msg, int client);
void cmd_info(const char **msg, int client);

#endif
/*
** EPITECH PROJECT, 2019
** commands.h
** File description:
** Commands function prototypes
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

# include <stdio.h>

void cmd_help(int *sock);
void cmd_login(int *sock);
void cmd_logout(int *sock);
void cmd_users(int *sock);
void cmd_user(int *sock);
void cmd_send(int *sock);
void cmd_messages(int *sock);
void cmd_subscribe(int *sock);
void cmd_subscribed(int *sock);
void cmd_unsubscribe(int *sock);
void cmd_use(int *sock);
void cmd_create(int *sock);
void cmd_list(int *sock);
void cmd_info(int *sock);

#endif
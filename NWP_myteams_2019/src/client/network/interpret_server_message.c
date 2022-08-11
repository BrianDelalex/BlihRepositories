/*
** EPITECH PROJECT, 2019
** interpret_server_message.c
** File description:
** interpret server messages
*/

#include "client/network/network.h"
#include "utils/protocol.h"
#include "myteams/logging_client.h"
#include "utils/str_to_tab.h"

void new_user_message(char *msg)
{
    char **strtab = str_to_tab(msg);
    client_event_loggedin(strtab[0], strtab[1]);
}

void user_disconnect_message(char *msg)
{
    char **strtab = str_to_tab(msg);
    client_event_loggedout(strtab[0], strtab[1]);
}

void interpret_server_message(char *msg)
{
    if (strncmp(msg, USR_CON, 1) == 0)
        new_user_message(msg + 1);
    else if (strncmp(msg, USR_DSC, 1) == 0)
        user_disconnect_message(msg + 1);
}
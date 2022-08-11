/*
** EPITECH PROJECT, 2019
** list.c
** File description:
** command list for ftp server
*/

#include "my_ftp.h"

void command_pwd(Client_t *client, __attribute__((unused)) char *msg)
{
    dprintf(client->clients, "%s %s created\n", PATH_NAME, client->paths);
}
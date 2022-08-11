/*
** EPITECH PROJECT, 2019
** cdup.c
** File description:
** cdup ftp command
*/

#include "my_ftp.h"

void command_cdup(Client_t *client, __attribute__((unused)) char *msg)
{
    char str[] = "CWD ../\r";
    command_cwd(client, str);
}
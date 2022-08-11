/*
** EPITECH PROJECT, 2019
** command_handler.h
** File description:
** command handler header
*/

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

# include <string.h>

# include "client/commands/commands.h"

typedef struct cmd_handler_s
{
    char const *msg[15];
    void (*handler[15])(int *);
}cmd_handler_t;

void *getHandlerFromCmd(char *msg);

#endif
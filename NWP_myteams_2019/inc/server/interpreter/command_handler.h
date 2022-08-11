/*
** EPITECH PROJECT, 2019
** command_handler.h
** File description:
** command handler header
*/

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "server/commands/commands.h"

struct cmd_handler_t
{
    char const *msg[15];
    void (*handler[15])(const char **msg, int client);
};

#define IS_EMPTY(x) (x == '\t' || x == '\r' || x == ' ')

char *strcut(const char *str);
char **str_to_tab(char const *str);
void free_tab(char const **tab);
bool command_handler(const char *msg, int client);
int lentab(char const **tab);

#endif
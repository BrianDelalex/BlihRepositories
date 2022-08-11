/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/context.h"
#include "def/typedef.h"
#include "def/macro.h"
#include "def/keyword.h"
#include <stdint.h>
#include <unistd.h>
#include <uuid/uuid.h>

struct datacontext_t *context = NULL;

void context_init(void)
{
    context = vmalloc(sizeof(struct datacontext_t));
    context->teams = list_init();
    context->users = list_init();
    context->active = NULL;
    context_restore();
}

void context_exit(int _unused __unused)
{
    context_save();
    free(context);
    exit(0);
}

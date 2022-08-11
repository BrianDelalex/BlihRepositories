/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/context.h"
#include "def/typedef.h"
#include "def/macro.h"
#include <stdint.h>
#include <unistd.h>
#include <uuid/uuid.h>

char const *uuid_new(void)
{
    uuid_t uuid;
    char *id = vmalloc(40);

    uuid_generate_random(uuid);
    uuid_unparse(uuid, id);
    return ((char const *)id);
}

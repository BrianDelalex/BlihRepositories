/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include "server/context.h"
#include "server/fsdatabase/model.h"
#include "def/typedef.h"
#include "def/macro.h"
#include <stdint.h>
#include <unistd.h>

void context_save(void)
{
    int fd = open(FSDATABASE_DATA, O_WRONLY | O_CREAT);
    list_t *users = context->users;
    struct user_t *user;

    if (!fd)
        return;
    while (users) {
        user = (struct user_t *)users->item;
        write(fd, user, sizeof(struct user_t));
        users = users->next;
    }
}
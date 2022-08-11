/*
** EPITECH PROJECT, 2019
** accept_connection.c
** File description:
** accept entering connection
*/

#include "server/network/network.h"
#include "server/context.h"
#include "server/interpreter/command_handler.h"
#include "myteams/logging_client.h"

int sig;

void signal_handler(__attribute__((unused))int signal)
{
    sig = 1;
}

int read_from_client(int client)
{
    char *buff = calloc(sizeof(char), 1024);

    if (read(client, buff, 1024) == -1)
    {
        free(buff);
        return (84);
    }
    set_current_user_from_fd(client);
    if (!command_handler(buff, client)) {
        if (write(client, "Unknow command", 16) == -1) {
            free(buff);
            return (84);
        }
    } else {
        free(buff);
        if (sig == 1) // || (context->active != NULL &&
        //context->active->fd == -1))
            return (84);
    }
    return (0);
}

int accept_connection2(int sock, list_t **clients, fd_set **rfsd, \
int *highest)
{
    int *new;
    struct sockaddr_in clientaddr;
    socklen_t size = sizeof(struct sockaddr_in);

    if (FD_ISSET(sock, *rfsd)) {
        new = malloc(sizeof(int));
        if ((*new = accept(sock, (struct sockaddr *) &clientaddr, \
        &size)) == -1) {
            return (84);
        }
        FD_SET(*new, *rfsd);
        *clients = list_add_node(*clients, ((void *)new));
        if (*new > *highest)
            *highest = *new;
    }
    return (0);
}

int accept_connection3(int sock, list_t **clients, fd_set **rfsd, int *highest)
{
    list_t *tmp2;
     if ((select(*highest + 1, *rfsd, NULL, NULL, NULL)) < 0)
            return (84);
    for (list_t *tmp = *clients; tmp != NULL;)
        if (tmp->item && FD_ISSET( *((int *)tmp->item), *rfsd)) {
            if (read_from_client( *((int *)tmp->item)) == 84) {
                set_current_user_from_fd(*((int *)tmp->item));
                context->active->connected = 0;
                FD_CLR( *((int*) tmp->item), *rfsd);
                close( *((int *) tmp->item));
                context->active->fd = -1;
                tmp2 = tmp->next;
                *clients = list_remove_node(*clients, tmp);
                tmp = tmp2;
                *highest = find_highest_fd(*clients, sock);
                if (*clients == NULL)
                    *clients = list_init();
            } else
               tmp = tmp->next;
        } else
            tmp = tmp->next;
    return (0);
}

void accept_connection(int sock)
{
    fd_set *rfsd = malloc(sizeof(fd_set));
    list_t *clients = list_init();
    int highest = sock;

    signal(SIGPIPE, signal_handler);
    FD_ZERO(rfsd);
    FD_SET(sock, rfsd);
    while (1) {
        sig = 0;
        if ( accept_connection3(sock, &clients, &rfsd, &highest) == 84)
            return;
        if (accept_connection2(sock, &clients, &rfsd, &highest) == 84)
            return;
        FD_ZERO(rfsd);
        FD_SET(sock, rfsd);
        for (list_t *tmp = clients; tmp != NULL; tmp = tmp->next)
            if (tmp->item)
                FD_SET( *((int *) tmp->item), rfsd);
    }
}
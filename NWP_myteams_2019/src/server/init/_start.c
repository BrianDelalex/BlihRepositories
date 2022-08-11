/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#include <limits.h>
#include <signal.h>
#include "server/context.h"
#include "server/network/network.h"

static void signal_init(void)
{
    signal(SIGKILL, context_exit);
    signal(SIGINT, context_exit);
    signal(SIGQUIT, context_exit);
}

int main(int argc, char **argv)
{
    int port;

    if (argc != 2)
        return (84);
    port = atoi(argv[1]);
    if (port > USHRT_MAX || port <= 0)
        return (84);
    context_init();
    signal_init();
    int sock = open_connection(port);
    if (sock == 84)
        return (84);
    accept_connection(sock);
    context_exit(0);
    return (0);
}
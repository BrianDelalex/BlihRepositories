/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** entry point of client.
*/

#include "client/errors/errors.h"
#include "client/network/network.h"

int main(int ac, char **av)
{
    if (av[1] && strcmp(av[1], "-help") == 0)
    {
        print_help();
        return (0);
    }
    if (check_options(ac, av) == 84)
        return (84);
    int sock = connection(av[1], av[2]);
    if (sock == 84)
        return (84);
    send_receive_message(sock);
    return (0);
}
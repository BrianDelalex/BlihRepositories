/*
** EPITECH PROJECT, 2019
** open_connection.c
** File description:
** open server sockets
*/

#include "server/network/network.h"

int open_connection(unsigned short port)
{
    struct sockaddr_in addr;
    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return (84);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &addr, \
    sizeof(struct sockaddr_in)) == - 1) {
        return (84);
    }
    if (listen(sock, RECEPTION_QUEUE) == -1) {
        return (84);
    }
    return (sock);
}
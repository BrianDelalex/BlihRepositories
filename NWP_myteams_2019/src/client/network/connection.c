/*
** EPITECH PROJECT, 2019
** connection.c
** File description:
** handle connection to server.c
*/

#include "client/network/network.h"

int connection(const char *ip, const char *port)
{
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
        exit(84);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(atoi(port));
    if (connect(sock, (struct sockaddr *) &server, \
    sizeof(struct sockaddr_in)) == -1) {
        exit(84);
    }
    return (sock);
}
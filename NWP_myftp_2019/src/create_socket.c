/*
** EPITECH PROJECT, 2019
** create_socket.c
** File description:
** create server socket
*/

#include "my_ftp.h"

int create_socket(ushort port)
{
    struct sockaddr_in my_sockaddr;
    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == - 1) {
        fprintf(stderr, "Unable to create socket.\n");
        return (-1);
    }
    my_sockaddr.sin_family = AF_INET;
    my_sockaddr.sin_port = htons(port);
    my_sockaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (bind(sock, (struct sockaddr *) &my_sockaddr, sizeof(struct sockaddr_in)) == - 1) {
        fprintf(stderr, "Unable to bind.\n");
        return (-1);
    }
    if (listen(sock, LISTEN_BACKLOG) == -1) {
        fprintf(stderr, "Unable to listen.\n");
        return (-1);
    }
    return (sock);
}
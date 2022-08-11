/*
** EPITECH PROJECT, 2019
** accept_connection.c
** File description:
** accepts connections
*/

#include "my_ftp.h"

void communication(Client_t *server)
{
    char *msg = calloc(sizeof(char), 1024);
    int rbyte;

    while (1)
    {
        if ((rbyte = read(server->clients, msg, 1024)) == -1) {
            free(server);
            return;
        }
        msg[rbyte] = 0;
        if (process(server, msg) == -1)
            return;
    }
}

void new_connection(Client_t *client)
{
    int pid = fork();

    if (pid == -1)
        return;
    if (pid == 0)
        communication(client);
    else 
        close(client->clients);
    free(client);
}

void accept_connection(int socket, char *path)
{
    struct sockaddr_in peer_addr;
    socklen_t sockaddr_size = sizeof(struct sockaddr_in);
    Client_t *client = calloc(sizeof(Client_t), 1);
    path = realpath(path, NULL);

    while (1)
    {
        if ((client->clients = accept(socket, ((struct sockaddr *) &peer_addr), &sockaddr_size)) == -1)
            myftp_exit(84, "Unable to accept connection.\n", client, NULL);
        dprintf(client->clients, "%s\n", "220");
        client->socket = socket;
        client->states = UNKWOWN;
        client->paths = path;
        new_connection(client);
        client = calloc(sizeof(Client_t), 1);
    }
}
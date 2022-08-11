/*
** EPITECH PROJECT, 2019
** commands2.c
** File description:
** handle ftp commands
*/

#include "my_ftp.h"

// void command_cdup(Client_t *server, __attribute__((unused))char *msg)
// {
//     if (strcmp(server->paths, "/") == 0) {
//         dprintf(server->clients, "%s\n", FILE_UNVAILABLE);
//         return;
//     }
//     if (server->paths[strlen(server->paths ) - 1] == '/')
//         server->paths[strlen(server->paths) - 1] = 0;
//     for (int i = (strlen(server->paths) - 1); i > 0 && server->paths[i] != '/'; i--)
//         server->paths[i] = 0;
//     dprintf(server->clients, "%s\n", COMMAND_OK);
// }

void command_quit(Client_t *server, __attribute__((unused))char *msg)
{
    dprintf(server->clients, "%s\n", QUIT);
    close(server->clients);
}

void command_port_error(Client_t *server, char *arg)
{
    dprintf(server->clients, "%s\n",RFC_ERROR);
    free(arg);
}

void command_port(Client_t *server, char *msg)
{
    char *arg = get_command_arg(msg);
    int port;
    struct sockaddr_in peer_addr;
    socklen_t sockaddr_size = sizeof(struct sockaddr_in);

    for (uint i = 0; arg[i]; i++)
        if (!IS_A_DIGIT(arg[i]))
        {
            command_port_error(server, arg);
            return;
        }
    if ((port = atoi(arg)) > USHRT_MAX)
    {
        command_port_error(server, arg);
        return;
    }
    server->dataSocket = create_socket(port);
    if (server->dataSocket == -1)
    {
        command_port_error(server, arg);
        return;
    }
    dprintf(server->clients, "%s\n", COMMAND_OK);
    if ((server->dataClients = accept(server->dataSocket, (struct sockaddr *) &peer_addr, &sockaddr_size)) == -1)
        printf("Error while accepting data socket\n");
    else
        printf("DATA SOCKET ACCEPTED\n");
    server->mode = ACTIVE;
}
/*
** EPITECH PROJECT, 2019
** send_receive_msg.c
** File description:
** send and receive msg to/from the server
*/

#include "client/network/network.h"
#include "client/interpreter/command_handler.h"

void (*handler)(int *);

int sig;

void signal_handler(__attribute__((unused))int signal)
{
    sig = 1;
}

int read_user_input(int sock)
{
    char *buf = calloc(sizeof(char), 1024);
    if (read(0, buf, 1024) == -1) {
        free(buf);
        return (84);
    }
    if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = 0;
    if (write(sock, buf, strlen(buf) + 1) == -1) {
        free(buf);
        return (84);
    }
    handler = (void (*)(int *)) getHandlerFromCmd(buf);
    free(buf);
    if (handler != NULL)
        (*handler)(&sock);
    return (0);
}

int read_from_server(int sock)
{
    char *buf = calloc(sizeof(char), 1024);
    if (read(sock, buf, 1024) == -1)
    {
        free(buf);
        return (-1);
    }
    interpret_server_message(buf);
    free(buf);
    return (0);
}

void set_fdset(fd_set *rfsd, int a, int b)
{
    FD_ZERO(rfsd);
    FD_SET(a, rfsd);
    FD_SET(b, rfsd);
}

int send_receive_message(int sock)
{
    fd_set rfsd;
    
    signal(SIGPIPE, signal_handler);
    set_fdset(&rfsd, 0, sock);
    while (1) {
        sig = 0;
        if (select(sock + 1, &rfsd, NULL, NULL, NULL) == -1)
            return (84);
        if (FD_ISSET(0, &rfsd))
            read_user_input(sock);
        if (FD_ISSET(sock, &rfsd))
            if (read_from_server(sock) == -1) {
                return (84);
            }
        set_fdset(&rfsd, 0, sock);
        if (sig == 1)
        {
            close(sock);
            return (84);
        }
    }
}
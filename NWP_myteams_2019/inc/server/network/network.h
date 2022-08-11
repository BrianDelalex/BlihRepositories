/*
** EPITECH PROJECT, 2019
** network.h
** File description:
** network header
*/

#ifndef NETWORK_SERVER_H_
#define NETWORK_SERVER_H_

# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <arpa/inet.h>
# include <sys/select.h>
# include <stdlib.h>
# include <unistd.h>
# include <poll.h>
# include <errno.h>
# include <stdio.h>
# include <signal.h>

# include "utils/list.h"

# define RECEPTION_QUEUE 50

int open_connection(unsigned short port);
int read_from_client(int client);
void accept_connection(int sock);
int accept_connection2(int sock, list_t **clients, fd_set **rfsd, int *highest);
int accept_connection3(int sock, list_t **clients, fd_set **rfsd, int *highest);
void remove_close_sock(fd_set *rfsd, list_t **clients);
void signal_handler(int);
void set_current_user_from_fd(int sock);
int find_highest_fd(list_t *clients, int sock);


#endif
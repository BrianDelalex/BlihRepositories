/*
** EPITECH PROJECT, 2019
** network.h
** File description:
** networking include and prototypes.
*/

#ifndef NETWORK_CLIENT_H_
#define NETWORK_CLIENT_H_

#include <stdlib.h>

# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <arpa/inet.h>
# include <sys/select.h>
# include <unistd.h>
# include <signal.h>

# include <string.h>
# include <stdio.h>

int connection(const char *ip, const char *port);
int send_receive_message(int sock);
int read_from_server(int sock);
int read_user_input(int sock);
void set_fdset(fd_set *rfsd, int a, int b);
void signal_handler(__attribute__((unused))int signal);
void interpret_server_message(char *msg);
void user_disconnect_message(char *msg);
void new_user_message(char *msg);

#endif
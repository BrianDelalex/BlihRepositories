/*
** EPITECH PROJECT, 2019
** check_options.c
** File description:
** checks binary option
*/

#include "client/errors/errors.h"

void print_help()
{
    printf("USAGE: ./myteams_cli ip port\n \
    ip is the server ip adress on which the server socket listens\n \
    port is the port number on which the server socket listens\n");
}

int is_an_ip(char *str)
{
    for (unsigned int i = 0; str[i]; i++) {
        if (!IS_C_AN_IP(str[i]))
            return (0);
    }
    return (1);
}

int is_a_port(char *str)
{
    int port;

    for (unsigned int i = 0; str[i]; i++) {
        if (!IS_A_DIGIT(str[i]))
            return (0);
    }
    port = atoi(str);
    if (port > USHRT_MAX)
        return (0);
    return (1);
}

int check_options(int ac, char **av)
{
    if (ac < 3) {
        printf("Arguments error - EXIT");
        return (84);
    }
    if (!is_an_ip(av[1])) {
        printf("Arguments error - EXIT");
        return (84);
    }
    if (!is_a_port(av[2])) {
        printf("Arguments error - EXIT");
        return (84);
    }
    return (0);
}
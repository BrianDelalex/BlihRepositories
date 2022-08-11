/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** entry point for myftp
*/

#include "error_managment.h"
#include "my_ftp.h"

int main(int ac, char **av)
{
    binInfo_t *infos;
    int socket;

    if (ac >= 2 && strcmp(av[1], "-help") == 0) {
        display_usage();
        exit(0);
    }
    infos = parsing(ac, av);
    if (infos == NULL)
        return (84);
    if ((socket = create_socket(infos->port)) == -1)
        myftp_exit(84, NULL, NULL, infos);
    accept_connection(socket, infos->path);
    printf("SUCCESS\n");
    myftp_exit(0, NULL, NULL, NULL);
}
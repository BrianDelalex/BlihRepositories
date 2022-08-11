/*
** EPITECH PROJECT, 2019
** error_managment.c
** File description:
** errors handling
*/

#include "error_managment.h"
#include "my_ftp.h"

void display_usage()
{
    printf("USAGE: ./myftp port path\n\tport\tis the port number on which the server socket listens\n\tpath\tis the path to the home directory for the Anonymous user\n");
}

binInfo_t *check_dir(char **av, binInfo_t *infos)
{
    struct stat st;
    int st_rtn = stat(av[2], &st);

    if (st_rtn == -1) {
        free(infos);
        fprintf(stderr, "Unable to open Dir: %s\n", av[2]);
        return (NULL);
    }
    if (!S_ISDIR(st.st_mode)) {
        free(infos);
        fprintf(stderr, "%s isn't a directory.\n", av[2]);
        return (NULL);
    }
    infos->path = malloc(sizeof(char) * (strlen(av[2]) + 1));
    infos->path = strcpy(infos->path, av[2]);
    return (infos);
}

void *parsing_error(const char *msg)
{
    fprintf(stderr, "%s",msg);
    return (NULL);
}

binInfo_t *parsing(int ac, char **av)
{
    binInfo_t *infos;
    int port;

    if (ac != 3) {
        display_usage();
        return (NULL);
    }
    for (uint i = 0; av[1][i]; i++) {
        if (!IS_A_DIGIT(av[1][i])) {
            display_usage();
            return (NULL);
        }
    }
    port = atoi(av[1]);
    if (port > USHRT_MAX)
        return (parsing_error("Out of range port\n"));
    if ((infos = malloc(sizeof(binInfo_t))) == NULL)
        return (parsing_error("Unable to malloc()\n"));
    infos->port = port;
    return (check_dir(av, infos));
}


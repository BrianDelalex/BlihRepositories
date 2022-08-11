/*
** EPITECH PROJECT, 2019
** commands3.c
** File description:
** handle ftp commands
*/

#include "my_ftp.h"

void command_pasv(Client_t *server, __attribute__((unused)) char *msg)
{
    if (server->dataSocket != 0 && server->dataSocket != -1)
        close(server->dataSocket);
}

void command_retr2(Client_t *server, char *path)
{
    struct stat st;
    int st_rtn;

    st_rtn = stat(path, &st);
    if (st_rtn == -1 || S_ISDIR(st.st_mode)) {
        dprintf(server->clients, "%s\n", RFC_ERROR);
    } else {
        dprintf(server->clients, "%s\n", FILE_STATUS_OK);
        if (server->mode == ACTIVE)
            send_file(server, path);
    }
}

void command_retr(Client_t *server, char *msg)
{
    char *arg = get_command_arg(msg);
    char *path;

    if (arg == NULL) {
        dprintf(server->clients, "%s\n", RFC_ERROR);
        return;
    }
    if (strncmp(arg, "./", 2) == 0 || arg[0] != '/') {
        path = get_path(server->paths, arg);
    } else {
        path = malloc(sizeof(char) * (strlen(arg) + 1));
        path = strcpy(path, arg);
    }
    command_retr2(server, path);
}
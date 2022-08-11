/*
** EPITECH PROJECT, 2019
** dele.c
** File description:
** dele command of ftp server
*/

#include "my_ftp.h"

void command_dele(Client_t *client, char *msg)
{
    char *arg = get_command_arg(msg);
    char *path = realpath(arg, NULL);
    int st_rtn;
    struct stat st;

    if (path == NULL) {
        dprintf(client->clients, "%s\n", FILE_UNVAILABLE);
        return;
    }
    st_rtn = stat(path , &st);
    if (st_rtn == - 1) {
        dprintf(client->clients, "%s\n", FILE_UNVAILABLE);
        return;
    }
    if (S_ISDIR(st.st_mode)) {
        dprintf(client->clients, "%s\n", FILE_UNVAILABLE);
        return;
    }
    st_rtn = remove(path);
    if (st_rtn == -1) {
        dprintf(client->clients, "%s\n", FILE_UNVAILABLE);
        return;
    }
    dprintf(client->clients, "%s\n", FILE_ACTION);


}
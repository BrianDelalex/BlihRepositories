/*
** EPITECH PROJECT, 2019
** exit.c
** File description:
** exit the programm
*/

#include "my_ftp.h"

void myftp_exit(int code, const char *msg, Client_t *serv, binInfo_t *info)
{
    if (serv != NULL) {
        close(serv->socket);
        free(serv);
    }
    if (info != NULL)
        free(info);
    if (msg != NULL)
        fprintf(stderr, "%s", msg);
    exit(code);
}
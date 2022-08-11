/*
** EPITECH PROJECT, 2019
** send_file.c
** File description:
** send file through tcp
*/

#include "my_ftp.h"

char *read_file(char *path)
{
    int file;
    struct stat st;
    int st_rtn = stat(path ,&st);
    char *data;

    if (st_rtn == -1)
        return (NULL);
    file = open(path, O_RDONLY);
    if (file == -1)
        return (NULL);
    data = malloc(st.st_size);
    for (int i = 0; read(file, (void *)(((uint64_t)data) + i) , 1); i++);
    return (data);
}

void send_file2(Client_t *serv, char *path)
{
    char *data = read_file(path);

    if (data == NULL) {
        write(serv->clients, RFC_ERROR, strlen(RFC_ERROR) + 1);
        return;
    }
    printf("%s\n", data);
    write(serv->dataClients, data, strlen(data));
    if (serv->mode == PASSIVE)
        write(serv->clients, CLOSING_DATA, strlen(CLOSING_DATA) + 1);
}

void send_file(Client_t *serv, char *path)
{
    int pid = fork();

    if (pid == -1) {
        write(serv->clients, RFC_ERROR, strlen(RFC_ERROR) + 1);
        return;
    }
    if (pid == 0) {
        send_file2(serv, path);
    }
}
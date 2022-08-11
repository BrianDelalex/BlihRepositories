/*
** EPITECH PROJECT, 2019
** process.c
** File description:
** Exec command received from clients
*/

#include "my_ftp.h"

int process2(Client_t *server, char *msg)
{
    int ok = 0;

    if (strncmp(msg, "CWD", 3) == 0) {
        command_cwd(server, msg);
        ok++;
    }
    if (strncmp(msg, "CDUP", 4) == 0) {
        command_cdup(server, msg);
        ok++;
    }
    if (strncmp(msg, "PORT", 4) == 0) {
        command_port(server, msg);
        ok++;
    }
    if (strncmp(msg, "RETR", 4) == 0) {
        command_retr(server, msg);
        ok++;
    }
    if (strncmp(msg, "PWD", 3) == 0) {
        command_pwd(server, msg);
        ok++;
    }
    if (strncmp(msg, "DELE", 4) == 0) {
        command_dele(server, msg);
        ok++;
    }
    if (ok == 0)
        write(server->clients, BAD_CMD, 4);
    return(0);
}

int process(Client_t *server, char *msg)
{
    if (strncmp(msg, "USER", 4) == 0) {
        command_user(server, msg);
        return (0);
    } else if (strncmp(msg, "PASS", 4) == 0) {
        command_pass(server, msg);
        return (0);
    } else if (strncmp(msg, "QUIT", 4) == 0) {
        command_quit(server, msg);
        return (-1);
    } else if (server->states != IDENTIFIED) {
        write(server->clients, NOT_LOGGED, 4);
    } else
        return (process2(server, msg));
    
    return (0);
}
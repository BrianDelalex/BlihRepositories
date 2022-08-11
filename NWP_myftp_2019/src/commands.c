/*
** EPITECH PROJECT, 2019
** commands.c
** File description:
** handle ftp commands
*/

#include "my_ftp.h"

char *get_command_arg(char *msg)
{
    char *start = strstr(msg, " ");
    char *end = strstr(msg, "\r");
    char *username;
    int i = 0;

    if (start == NULL) {
        username = malloc(sizeof(char));
        username[0] = 0;
        return (username);
    }
    if (end == NULL) {
        printf("NULL\n");
        return (NULL);
    }
    username = malloc(sizeof(char) * ( ((uint64_t) end) - ((uint64_t) start)));
    start = ((char *) ((int64_t) start) + 1);
    for (; start != end; start++, i++)
        username[i] = *start;
    username[i] = 0;
    return (username);
}

void command_user(Client_t *server, char *msg)
{
    char *username = get_command_arg(msg);

    if (username == NULL) {
        dprintf(server->clients, "%s\n",INVALID_USER_NAME);
        return;
    }
    if (server->usernames == NULL) {
        server->usernames = username;
        dprintf(server->clients, "%s\n",USERNAME_OK);
    } else {
        dprintf(server->clients, "%s\n", BAD_SEQ);
        free (username);
    }
}

void command_pass(Client_t *server, char *msg)
{
    char *pass = get_command_arg(msg);

    if (pass == NULL)
        dprintf(server->clients, "%s\n",INVALID_USER_NAME);
    else
    {
        if (server->usernames == NULL) {
            dprintf(server->clients, "%s\n",NEED_ACC);
            return;
        }
        if (server->states == IDENTIFIED)
            dprintf(server->clients, "%s\n", BAD_SEQ);
        else if (strcmp(pass, "") == 0) {
            dprintf(server->clients, "%s\n", USER_LOGGED);
            server->states = IDENTIFIED;
        } else {
            dprintf(server->clients, "%s\n", INVALID_USER_NAME);
        }
        
    }
    free(pass);
}

char *get_path(char *path, char *arg)
{
    int add = 0;
    char *rtn = malloc(sizeof(char) * (strlen(arg) + strlen(path) + 2));
    if (path[strlen(path) - 1] == '/' && arg[0] == '/')
        path[strlen(path) - 1] = 0;
    if (path[strlen(path) - 1] != '/' && arg[0] != '/')
        add = 1;
    if (add == 1) {
        rtn = strcat(path, "/");
        return (strcat(rtn, arg));
    }
    rtn = strcat(path, arg);
    return (rtn);
}

void command_cwd(Client_t *server, char *msg)
{
    char *arg = get_command_arg(msg);
    char *path;
    struct stat st;
    int st_rtn;

    if (arg == NULL || strcmp(arg, "") == 0) {
        dprintf(server->clients, "%s\n", SYNTAX_ERROR);
        return;
    }
    if (strncmp(arg, "./", 2) == 0 || arg[0] != '/') {
        path = get_path(server->paths, arg);
    } else {
        path = malloc(sizeof(char) * (strlen(arg) + 1));
        path = strcpy(path, arg);
    }
    
    st_rtn = stat(path, &st);
    if (st_rtn == -1 || !S_ISDIR(st.st_mode)) {
        dprintf(server->clients, "%s\n", FILE_UNVAILABLE);
    } else {
        char *resolved;
        printf("%s\n", path);
        if ( ( resolved = realpath(path, NULL)) == NULL) {
            dprintf(server->clients, "%s\n", FILE_UNVAILABLE);
        } else {
            server->paths = resolved;
            dprintf(server->clients, "%s\n", FILE_ACTION);
        }
        
    }
    printf("%s\n", server->paths);
    free(arg);
}
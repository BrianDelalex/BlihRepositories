/*
** EPITECH PROJECT, 2019
** my_ftp.h
** File description:
** my_ftp header
*/

#ifndef MY_FTP_H_
#define MY_FTP_H_

typedef unsigned int uint;
typedef unsigned short ushort;

#define IS_A_DIGIT(c) (c >= 48 && c <= 57)
#define LISTEN_BACKLOG 50

#define USER_LOGGED "230" //User logged in, proceed.<CRLF>"
#define USERNAME_OK "331" //<SP>User name okay, need password.<CRLF>"
#define RFC_ERROR "xxx" //<SP>Error (RFC compliant)<CRLF>"
#define BAD_CMD "500"
#define NOT_LOGGED "530"
#define INVALID_USER_NAME "430"
#define SYNTAX_ERROR "501"
#define NEED_ACC "332" //<SP>Need account for login.<CRLF>"
#define FILE_ACTION "250" //<SP>Requested file action okay, completed.<CRLF>"
#define COMMAND_OK "200" //<SP>Command okay.<CRLF>"
#define QUIT "221"
#define FILE_STATUS_OK "150" //<SP>File status okay; about to open data connection.<CRLF>"
#define CLOSING_DATA "226" //<SP>Closing data connection.<CRLF>"
#define BAD_SEQ "503"
#define FILE_UNVAILABLE "550"
#define PATH_NAME "257"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>


/* NETWORK DEPENDENCIES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

enum State
{
    IDENTIFIED,
    UNKWOWN
};

enum DataMode
{
    PASSIVE,
    ACTIVE
};

typedef struct binInfo_s
{
    char *path;
    ushort port;
}binInfo_t;

typedef struct Client_s
{
    int socket;
    int dataSocket;
    int mode;
    int clients;
    int dataClients;
    int states;
    char *usernames;
    char *paths;
}Client_t;

int create_socket(ushort port);
//Server_t *init_server(int ac, char **av);
//void init_server2(Server_t **server, binInfo_t *infos);
void myftp_exit(int code, const char *msg, Client_t *serv, binInfo_t *info);
void accept_connection(int socket, char *path);
void communication(Client_t *server);
int process2(Client_t *server, char *msg);
int process(Client_t *server, char *msg);
void command_user(Client_t *server, char *msg);
char *get_command_arg(char *msg);
void command_pass(Client_t *server, char *msg);
void command_cwd(Client_t *server, char *msg);
char *get_path(char *path, char *arg);
void command_cdup(Client_t *server, char *msg);
void command_quit(Client_t *server, char *msg);
void command_port(Client_t *server, char *msg);
void command_port_error(Client_t *server, char *arg);
void send_file(Client_t *serv, char *path);
void send_file2(Client_t *serv, char *path);
char *read_file(char *path);
void command_retr(Client_t *server, char *msg);
void command_retr2(Client_t *server, char *path);
void command_pasv(Client_t *server, char *msg);
void command_pwd(Client_t *client, char *msg);
void command_dele(Client_t *client, char *msg);
void new_connection(Client_t *client);

#endif
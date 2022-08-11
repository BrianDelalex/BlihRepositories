/*
** EPITECH PROJECT, 2018
** create_message.c
** File description:
** creates message matrix
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

void alloc_mess_matrix(t_control *control, char *message)
{
    int len = my_strlen(message);

    while (len % control->key_size != 0)
        len = len + 1;
    control->mess_size = len / control->key_size;
    control->mess = malloc(sizeof(int *) * control->mess_size);
    for (int i = 0; i < control->mess_size && i < len; i ++)
        control->mess[i] = malloc(sizeof(int) * control->key_size);
}

void create_message(t_control *control, char *message)
{
    int len = my_strlen(message);
    int i = 0;
    int j = 0;
    int ct = 0;

    alloc_mess_matrix(control, message);
    for (i = 0; i < control->mess_size; i++ && ct <= len) {
        j = 0;
        for (j = 0; j < control->key_size && ct <= len; j++, ct++)
            control->mess[i][j] = message[ct];
    }
    for (; i < control->mess_size; i++)
        for (; j < control->key_size; j++)
            control->mess[i][j] = 0;
}

void alloc_decrypt_matrix(t_control *control, char *message)
{
    int len = 1;

    for (int i = 0; message[i] != '\0'; i++)
        if (message[i] == 32)
            len = len + 1;
    while (len % control->key_size != 0)
        len = len + 1;
    control->mess_size = len / control->key_size;
    control->mess = malloc(sizeof(int *) * control->mess_size);
    for (int i = 0; i < control->mess_size && i < len; i ++)
        control->mess[i] = malloc(sizeof(int) * control->key_size);
}

int find_number(char *message, int *ct)
{
    int nb = 0;

    while (message[*ct] != 32 && message[*ct] != '\0') {
        nb = nb * 10;
        nb = nb + my_getdigit(message[*ct]);
        *ct = *ct + 1;
    }
    *ct = *ct + 1;
    return (nb);
}

void create_message2(t_control *control, char *message)
{
    int ct = 0;

    alloc_decrypt_matrix(control, message);
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++)
            control->mess[i][j] = find_number(message, &ct);
}

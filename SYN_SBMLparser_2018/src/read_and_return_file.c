/*
** EPITECH PROJECT, 2019
** read_and_return_file.c
** File description:
** read the file and save it in char** before returning
*/

#include "../include/my.h"

char **read_and_return_file(FILE *file)
{
    char *ipt = NULL;
    char **xbml = NULL;

    ipt = use_getline(file);
    while (ipt != NULL) {
        ipt = use_getline(file);
        if (ipt == NULL)
            break;
        ipt = cut_repetitiv_char(ipt, 32);
        xbml = add_str_to_tab(ipt, xbml);
    }
    return (xbml);
}

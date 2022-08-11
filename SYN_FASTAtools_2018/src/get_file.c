/*
** EPITECH PROJECT, 2019
** get_file.c
** File description:
** get file from stdin
*/

#include "../include/my.h"

char **get_file(void)
{
    char **file = NULL;
    char *ipt = NULL;

    ipt = use_getline();
    if (ipt != NULL)
        file = add_str_to_tab(ipt, file);
    while (ipt != NULL) {
        ipt = use_getline();
        if (ipt == NULL)
            break;
        if (!(my_strcmp(ipt, "EMPTY")))
            file = add_str_to_tab(ipt, file);
    }
    return (file);
}

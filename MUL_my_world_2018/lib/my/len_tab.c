/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls
*/

#include "../../include/my.h"

char *return_get_line(char *buff, char *ret)
{
    free(buff);
    return (ret);
}

int len_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

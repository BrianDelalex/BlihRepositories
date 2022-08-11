/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls
*/

#include "../../include/my.h"

int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}

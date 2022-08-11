/*
** EPITECH PROJECT, 2019
** display_bin_error.c
** File description:
** displays binaries errors
*/

#include "minishell1.h"

void display_bin_error(int wstatus)
{
    if (wstatus == 11 || wstatus == 139)
        my_putstr("Segmentation fault\n");
    if (wstatus == 136 || wstatus == 8)
        my_putstr("Floating exception\n");
}

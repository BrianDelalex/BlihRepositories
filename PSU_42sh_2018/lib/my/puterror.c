/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

void puterror(char *s)
{
    for (int i = 0; s[i]; i++)
        write(2, &s[i], 1);
}

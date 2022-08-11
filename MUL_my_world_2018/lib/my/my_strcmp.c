/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if (s1[i] == '\0' && s2[i] == '\0')
        return (1);
    return (-1);
}

/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** displays_str
*/

#include <unistd.h>
#include "utils.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (my_strlen(str));
}

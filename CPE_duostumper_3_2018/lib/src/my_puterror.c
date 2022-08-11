/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** displays_str
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return (my_strlen(str));
}

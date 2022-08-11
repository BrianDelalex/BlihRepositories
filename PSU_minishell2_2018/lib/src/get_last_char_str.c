/*
** EPITECH PROJECT, 2019
** get_last_char_str.c
** File description:
** returns the last char of the given str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char get_last_char_str(char *str)
{
    int len = my_strlen(str);
    return (str[len - 1]);
}

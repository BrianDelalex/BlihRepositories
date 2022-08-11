/*
** EPITECH PROJECT, 2019
** remove_char_from_str.c
** File description:
** remove char from char *
*/

#include <stdlib.h>
#include "utils.h"

char *remove_char_from_str(char *str)
{
    int len = my_strlen(str);

    if (len == 1)
        return (NULL);
    str[len - 1] = 0;
    return (str);
}

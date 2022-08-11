/*
** EPITECH PROJECT, 2018
** convert_to_hexa.c
** File description:
** convert an int to an hexa value return in a char *
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *add_char_to_str(char c, char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = my_strlen(str);

    for (; i - 1 >= 0; i--) {
        res[i] = str[i - 1];
    }
    res[0] = c;
    res[my_strlen(str) + 1] = 0;
    return (res);
}

char convert_number_to_hexa_char(char c, int min)
{
    switch (c) {
    case 10:
        return ('A' + min);
    case 11:
        return ('B' + min);
    case 12:
        return ('C' + min);
    case 13:
        return ('D' + min);
    case 14:
        return ('E' + min);
    case 15:
        return ('F' + min);
    }
}

char *convert_to_hexa(int nb, int min)
{
    char *res = {"\0"};
    char c = 0;

    while (nb > 0) {
        c = nb % 16;
        if (c >= 10)
            c = convert_number_to_hexa_char(c, min);
        else
            c = c + 48;
        res = my_strcpy(res, add_char_to_str(c, res));
        nb = nb / 16;
    }
    return (res);
}

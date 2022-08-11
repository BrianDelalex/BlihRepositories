/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** rev a str
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char *rev = malloc(sizeof(char) * (len + 1));
    int j = 0;

    for (int i = len - 1; str[i] && i >= 0; i--, j++) {
        rev[j] = str[i];
    }
    rev[len] = 0;
    return (rev);
}

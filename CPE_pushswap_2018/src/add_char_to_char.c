/*
** EPITECH PROJECT, 2018
** add_char_to_char.c
** File description:
** adds a char to an other char.
*/

#include <stdlib.h>

int my_strlen(char *str);

char *add_char_to_char(char *src, char *target)
{
    int len = my_strlen(target);
    int i = 0;
    char *tmp = malloc(sizeof(char) * (len + 4));

    for (int j = 0; target[i] != 0; i++)
        tmp[i] = target[i];
    for (i = 0; src[i] != '\0'; i++) {
        tmp[len + i] = src[i];
    }
    tmp[len + i] = '\0';
    free(target);
    return (tmp);
}

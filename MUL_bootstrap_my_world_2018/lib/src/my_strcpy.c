/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copie a string into an other
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

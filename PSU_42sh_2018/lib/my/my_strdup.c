/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copie a string into an other
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *src)
{
    int i = 0;
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

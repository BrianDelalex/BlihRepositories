/*
** EPITECH PROJECT, 2018
** mem_alloc.c
** File description:
** allocate enought memory to store the 2 given strings
*/

#include "include/my.h"
#include <stdlib.h>

char *mem_alloc(char *a, char *b)
{
    char *res = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));
    int i = 0;
    
    for (; a[i]; i++) {
        res[i] = a[i];
    }
    for (int j = 0; b[j]; i++, j++) {
        res[i] = b[j];
    }
    res[i] = '\0';
    return (res);
}
/*
** EPITECH PROJECT, 2019
** realloc_array.c
** File description:
** My realloc array
*/

#include "stdio.h"
#include "my.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb * size > UINT_MAX)
        return (NULL);
    if (nmemb == 0 || size == 0)
        return (NULL);
    void *tmp = realloc(ptr, nmemb * size);
    if (tmp == NULL)
        return (NULL);
    tmp = memset(tmp, 0, nmemb * size);
    return (tmp);
}
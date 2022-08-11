/*
** EPITECH PROJECT, 2019
** macro.h
** File description:
** macro.h
*/

#ifndef _PERSMACRO_H_
#define _PERSMACRO_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

static inline int absl(int x)
{
    return (x *= (x < 0x0) ? -0x1 : 0x1);
}

static inline void pexit(__attribute__((unused))char const *s)
{
    exit(84);
}

static inline void *vmalloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
        pexit("Malloc failed");
    return (ptr);
}

#endif

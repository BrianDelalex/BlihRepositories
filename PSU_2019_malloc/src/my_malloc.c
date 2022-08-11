/*
** EPITECH PROJECT, 2019
** my_malloc.c
** File description:
** my_malloc
*/

#include "my.h"
#include "stdio.h"
void *memptr = NULL;

void *malloc2(size_t size)
{
    int *_size = (int *) memptr;
    void *tmp = memptr;
    void *save;
    _size = (int *)tmp;
    for (; *_size != 0; tmp = NEXT_PTR(tmp, abs(*_size)), _size = (int *)tmp) {
        if (*_size < 0 && abs(*_size) >= size) {
            *_size = abs(*_size);
            return (ADD_PTR(tmp, sizeof(int)));
        }
    }
    *_size = size;
    while ( ((uint64) NEXT_PTR(tmp, size) + sizeof(int)) > ((uint64) sbrk(0)))
        if (sbrk(PAGE_SIZE * 2) == (void *) -1)
            return (NULL);
    save = ((void *) ((uint64) tmp + sizeof(int) ) );
    tmp = NEXT_PTR(tmp, size);
    _size = (int *) tmp;
    *_size = 0;
    return (save);
}

void *malloc(size_t size)
{
    if (size == 0)
        return (NULL);
    for (; !is_binary(size + sizeof(int)); size++);
    if (memptr == NULL) {
        memptr = sbrk(0);
        if ( (int)((uint64) sbrk(0) % (4096 * 2)) != 0)
            brk( (void *)((uint64) sbrk(0) + ((PAGE_SIZE * 2) \
            - ((uint64)sbrk(0) % (PAGE_SIZE * 2)))));
        while ((uint64) memptr + size + sizeof(int) * 2 > (uint64) sbrk(0))
            if (sbrk(4096 * 2) == (void *) -1)
                return (NULL);
        int *b = (int *)memptr;
        *b = size;
        void *tmp = NEXT_PTR(memptr, size);
        int *c = tmp;
        *c = 0;
        return ((void *) ( (uint64) memptr + sizeof(int)));
    }
    return (malloc2(size));
}

void free(void *ptr)
{
    int *_size = (int *) memptr;
    void *tmp = NEXT_PTR(memptr, *_size);

    if (ptr == NULL)
        return;
    if ((uint64) ADD_PTR(memptr, sizeof(int)) == (uint64) ptr) {
        if (*_size < 0)
            return;
        else {
            *_size = -(*_size);
            return;
        }
    }
    _size = (int *) tmp;
    for (; *_size != 0 && (uint64) ADD_PTR(tmp, sizeof(int)) != (uint64) ptr \
    ; tmp = NEXT_PTR(tmp, abs(*_size)), _size = (int *)tmp);
    if ((uint64) ADD_PTR(tmp, sizeof(int)) == (uint64) ptr) {
        if (*_size < 0)
            return;
        else
            *_size = -(*_size);
    }
}

void *calloc(size_t nmemb , size_t size)
{
    if (nmemb * size > UINT_MAX)
        return (NULL);
    if (nmemb == 0 || size == 0)
        return (NULL);
    void *ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    ptr = memset(ptr, 0, nmemb * size);
    return (ptr);
}

void *realloc(void *ptr, size_t size)
{
    int *_size;
    void *tmp;
    void *tmp2;

    if (block_exist(ptr) == 0)
        return (malloc(size));
    tmp = SUB_PTR(ptr, sizeof(int));
    _size = (int *) tmp;
    if (*_size >= (int) size)
        return (ptr);
    else {
        tmp2 = malloc(size);
        tmp2 = memcpy(tmp2, ADD_PTR(tmp, sizeof(int)), *_size);
        free (ADD_PTR(tmp, sizeof(int)));
        return (tmp2);
    }
}
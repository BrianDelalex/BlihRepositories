/*
** EPITECH PROJECT, 2019
** handle_block.c
** File description:
** functions to handle mem blocks
*/

#include "my_malloc.h"

extern void *memptr;

int block_exist(void *ptr)
{
    if (ptr == NULL)
        return (0);
    int *_size = (int *) memptr;
    void *tmp = memptr;
    for (; *_size != 0 && ((uint64) ADD_PTR(tmp, sizeof(int))) != \
    (uint64) ptr; tmp = NEXT_PTR(tmp, abs(*_size)), _size = (int *) tmp);
    if (((uint64) ADD_PTR(tmp, sizeof(int))) == (uint64) ptr)
        return (1);
    return (0);
}
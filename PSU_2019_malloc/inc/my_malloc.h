/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include "my.h"
#include "string.h"
#include "limits.h"

#define PAGE_SIZE 0x1000
typedef uint64_t uint64;

#define ADD_PTR(ptr, size) ( (void *) (((uint64) ptr) + size))
#define NEXT_PTR(ptr, size) ( (void *) \
(((uint64) ADD_PTR(ptr, size)) + sizeof(int) ))
#define SUB_PTR(ptr, size) ( (void *) (((uint64) ptr) - size))

void free(void *ptr);
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
int block_exist(void *ptr);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif

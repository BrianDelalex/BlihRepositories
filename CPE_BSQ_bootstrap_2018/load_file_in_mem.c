/*
** EPITECH PROJECT, 2018
** load_file_in_mem.c
** File description:
** loads file's content in memory and returns memory area's address
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

char *load_file_in_mem(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    char buffer[51];
    char *res = {""};
    int size = 50;

    while (size == 50) {
        size = read(fs, buffer, 50);
        if (size < 50)
            break;
        buffer[50] = 0;
        res = mem_alloc(res, buffer);
    }
    if (size == 0)
        return (res);
    else {
        for (int i = 49; i > size - 1; i--) 
            buffer[i] = 0;
        res = mem_alloc(res, buffer);
    }
    return (res);
}
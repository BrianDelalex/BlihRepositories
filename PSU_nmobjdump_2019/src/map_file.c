/*
** EPITECH PROJECT, 2019
** map_file.c
** File description:
** Allocating memory to read elf file
*/

#include "nmobjdump.h"

void *map_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    void *ptr;
    struct stat *st = malloc(sizeof(struct stat));

    if (fd == -1) {
        return (NULL);
    }
    if (stat(filename, st) == -1) {
        printf("Can't stat %s.\n", filename);
        return (NULL);
    }
    if (!S_ISREG(st->st_mode)) {
        printf("%s isn't a regular file.\n", filename);
        return (NULL);
    }
    ptr = mmap(NULL, st->st_size, PROT_READ, MAP_SHARED, fd, 0);
    return (ptr);
}
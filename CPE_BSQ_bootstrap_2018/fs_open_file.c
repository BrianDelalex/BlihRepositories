/*
** EPITECH PROJECT, 2018
** fs_open_file.c
** File description:
** takes a path as an argument, opens the file at te given path, displays SUCCESS\n or FAILURE\n and returns a file descriptor
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"

int fs_open_file(char const *filepath)
{
    int fs = 0;

    fs = open(filepath, O_RDONLY);
    if (fs == -1)
        my_putstr("FAILURE\n");
    else
        my_putstr("SUCCESS\n");
    return (fs);
}

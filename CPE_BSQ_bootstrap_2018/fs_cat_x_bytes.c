/*
** EPITECH PROJECT, 2018
** fs_cat_x_bytes.c
** File description:
** read the x first bytes of a given file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

void fs_cat_x_bytes(char const * filepath, int x)
{
    int fs = open(filepath, O_RDONLY);
    char buffer[x + 1];
    int size = 0;

    if (fs == -1)
        my_putstr("error while opening file");
    size = read(fs, buffer, x);
    buffer[x] = '\0';
    my_putstr(buffer);
    close(fs);
}
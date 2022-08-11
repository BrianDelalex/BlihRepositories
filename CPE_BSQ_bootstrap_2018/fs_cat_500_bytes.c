/*
** EPITECH PROJECT, 2018
** fs_cat_500_bytes.c
** File description:
** displays the first 500 bytes of a file passed as parameter
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

void fs_cat_500_bytes(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    char buffer[501];
    int size = 0;

    if (fs == -1)
        my_putstr("error while opening file");
    size = read(fs, buffer, 500);
    buffer[500] = '\0';
    my_putstr(buffer);
    close(fs);
}
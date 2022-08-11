/*
** EPITECH PROJECT, 2018
** fs_print_first_line.c
** File description:
** displays the first line of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

void fs_print_first_line(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    char buffer[201];
    int size = 0;

    size = read(fs, buffer, 200);
    buffer[200] = 0;
    for (int i = 0; buffer[i] != '\n'; i++) {
        my_putchar(buffer[i]);
    }
    close(fs);
}
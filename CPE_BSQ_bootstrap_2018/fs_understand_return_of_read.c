/*
** EPITECH PROJECT, 2018
** fs_understand_return_of_read.c
** File description:
** displays a specific message according to read return
*/

#include <unistd.h>
#include "include/my.h"

void fs_understand_return_of_read(int fs, char *buffer, int size)
{
    int read_size = 0;

    read_size = read(fs, buffer, size);
    if (read_size == -1)
        my_putstr("read failed\n");
    else if (read_size == 0)
        my_putstr("read has nothing more to read\n");
    else if (read_size < size)
        my_putstr("read didn't complete the entire buffer\n");
    if (read_size == size)
        my_putstr("read completed the entire buffer\n");
}
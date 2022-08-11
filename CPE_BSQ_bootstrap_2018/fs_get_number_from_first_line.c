/*
** EPITECH PROJECT, 2018
** get_number_from_first_line.c
** File description:
** get the positive number on a first line of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

int my_getdigit(char c)
{
    int res = 0;
    if (c >= 48 && c <= 57)
        res = c - 48;
    return (res);
}

int get_number_from_first_line(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    char buffer[201];
    int size = 0;
    int res = 0;

    if (fs == -1)
        return (-1);
    size = read(fs, buffer, 200);
    buffer[200] = '\0';
    if (size == 0 || size == -1)
        return (-1);
    for (int i = 0; buffer[i] != '\n'; i++)
    {
        if (buffer[i] < 48 || buffer[i] > 57)
            return (-1);
        else {
            res = res * 10;
            res = res + my_getdigit(buffer[i]);
        }
    }
    return (res);
}

/*
** EPITECH PROJECT, 2018
** find_nb_of_cols.c
** File description:
** finds the number of cols in the file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int find_nb_of_cols(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    int size = 1;
    int cols = 0;
    char buffer[101];
    int i = 0;

     while (size != 0) {
        size = read(fs, buffer, 100);
        if (size < 100) {
            buffer[size] = 0;
            size = 0;
        } else
            buffer[100] = 0;
        for (; buffer[i] != '\n' && i < 100; i++, cols++);
        if (buffer[i] == '\n')
            break;
        i = 0;
    }
    close(fs);
    return (cols);
}

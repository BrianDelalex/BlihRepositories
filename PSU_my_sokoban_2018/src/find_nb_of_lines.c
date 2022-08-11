/*
** EPITECH PROJECT, 2018
** find_nb_of_lines.c
** File description:
** finds the number of line in the file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void count_backspace(char const *buffer, int *lines)
{
    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n')
            *lines = *lines + 1;
    }
}

int find_nb_of_lines(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    int size = 1;
    int lines = 0;
    char buffer[101];

    while (size != 0) {
        size = read(fs, buffer, 100);
        if (size < 100) {
            buffer[size] = 0;
            size = 0;
        } else 
            buffer[100] = 0;
        count_backspace(buffer, &lines);
    }
    close(fs);
    return (lines);
}
